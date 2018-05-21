_par = params [["_veh",objNull,[objNull]]];
if ((!_par) || (isNull _veh) || !(_veh isKindOf "vurtual_hmmwv_base")) exitWith {false};
 if (local _veh) then {[_veh, """", [], true] call bis_fnc_initVehicle;};
if (_veh getVariable ["hmmwv_init",false]) exitWith {false};
_veh setVariable ["hmmwv_init",true];

_veh setMass (getMass _veh)+(getNumber (configFile >> "CfgVehicles" >> (typeOf _veh) >> "vurtual_hmmwv_addweight"));

if (is3DEN) exitWith {true};
_veh addAction ["Lights: Blackout",{_veh = (_this select 0);_veh animateSource ["blackout_hide",0]; _veh animateSource ["brakelight_normal_hide",1];},[],1.5,false,true,"","(alive _target) && !(isLightOn _target) && (driver _target == _this) && (_target animationSourcePhase 'blackout_hide')==1"];
_veh addAction ["Lights: Stoplight",{_veh = (_this select 0); _veh animateSource ["blackout_hide",1]; _veh animateSource ["brakelight_normal_hide",0];},[],1.5,false,true,"","(alive _target) && !(isLightOn _target) && (driver _target == _this) && (_target animationSourcePhase 'brakelight_normal_hide')==1"];
_veh addAction ["Lights: None",{_veh = (_this select 0); _veh animateSource ["blackout_hide",1]; _veh animateSource ["brakelight_normal_hide",1];},[],1.5,false,true,"","(alive _target) && !(isLightOn _target) && (driver _target == _this) && ((_target animationSourcePhase 'brakelight_normal_hide')==0 || (_target animationSourcePhase 'blackout_hide')==0)"];
/*if (_veh isKindOf "vurtual_hmmwv_base_ecv") then {
	_veh addAction ["Open/Close Window",{
		(_this select 0) animateDoor ["ecv_window_open",abs ((_this select 0 animationSourcePhase "ecv_window_open")-1)];
	},[],1.5,false,true,"","(_target getCargoIndex _this)==0"];
} else {
[
	_veh,
	"Install/Remove doors",
	"",
	"",
	"alive _target && (driver _target == _this) && !isEngineOn _target",
	"alive _target && (driver _target == _this) && !isEngineOn _target",
	{},
	{},
	{
		(_this select 0) animateDoor ["door_hide",abs ((_this select 0 animationSourcePhase "door_hide")-1)];
	},
	{},
	[],
	10,
	0,
	false,
	false
] call BIS_fnc_holdActionAdd;
};*/
_arr = [["window_codriver",0]];

if (getNumber (configFile >> "CfgVehicles" >> (typeOf _veh) >> "vurtual_hmmwv_4door")==1) then {
	_arr=_arr+[["window_left",1],["window_right",2]];
};
if (_veh isKindOf "vurtual_gmv") then { _arr=[]};
{
	_veh addAction ["Open/Close Window",{
		(_this select 0) animateDoor [(_this select 3 select 0),abs ((_this select 0 animationSourcePhase (_this select 3 select 0))-1)];
	},[_x select 0],1.5,false,true,"",format["(_target animationSourcePhase 'door_hide')==0 && (_target getCargoIndex _this)==%1",_x select 1]];
} forEach _arr;


_veh addAction ["Load vehicle",{
	(_this select 0) setVehicleCargo (vehicle (_this select 1));
},[],1.5,false,true,"","!boxloader_maxload_enabled && (_this != vehicle _this) && (_this == driver vehicle _this) && (_target canVehicleCargo vehicle _this) select 0 && ((vehicle _this distance _target)<15) && ([(_target modeltoworld (_target selectionPosition 'VTV_exit_1')),(getDir _target+180),30,position vehicle _this] call bis_fnc_inAngleSector)"];
if (isClass(configFile >> "CfgPatches" >> "Boxloader")) then {
	[_veh,"VTV_exit_1"] call boxloader_fnc_driveon;
};

if (_veh isKindOf "vurtual_hmmwv_base") then {[_veh] call vurtual_m998_fnc_passenger;};

[_veh] spawn {
	_veh = (_this select 0);
	while {alive (_veh)} do {
		sleep 0.1;
		if (local _veh) then {
			_fordingSafe = "fordingkit_kill"; //disabled fordingkit_safe for now
			_fordingKill = "fordingkit_kill";
			_fordingExhaust = "fordingkit_exhaust";
			_fordingExhaustKill="fording_safe";
			_noSafe = true;
			if ((_veh animationSourcePhase "fordingkit_hide")==1) then {
				_fordingSafe = "fording_safe";
				_fordingKill = "fording_kill";
				_fordingExhaust = "fording_exhaust";
				_noSafe = false;
			};
			if (isNull attachedTo _veh) then {
				if (((AGLToASL (_veh modelToWorld (_veh selectionPosition _fordingKill))) select 2 < 0) && ((AGLToASL (_veh modelToWorld (_veh selectionPosition "fording_safe"))) select 2 < 0)) then {
					_veh setHitPointDamage ["hitEngine",1];
				};
				if (vurtual_m998_fording_damage) then {
					if (!_noSafe && (AGLToASL (_veh modelToWorld (_veh selectionPosition _fordingSafe))) select 2 < 0) then {
						_veh setHitPointDamage ["hitEngine",(_veh getHitPointDamage "hitEngine")+0.0025];
					};
					if (!isEngineOn _veh && ((AGLToASL (_veh modelToWorld (_veh selectionPosition _fordingExhaust))) select 2 < 0) && ((AGLToASL (_veh modelToWorld (_veh selectionPosition _fordingExhaustKill))) select 2 < 0)) then {
						_veh setHitPointDamage ["hitEngine",1];
					};
					if (((AGLToASL (_veh modelToWorld (_veh selectionPosition "fording_safe"))) select 2 < 0) && (abs speed _veh)>12) then {
						_veh setHitPointDamage ["hitEngine",(_veh getHitPointDamage "hitEngine")+(0.0025*((abs speed _veh/80) min 1))];
					};
				};
			};
			if ((isLightOn _veh) && ((_veh animationSourcePhase 'blackout_hide')==0 || (_veh animationSourcePhase 'brakelight_normal_hide')==1)) then {
				_veh animateSource ["brakelight_normal_hide",0];
				_veh animateSource ["blackout_hide",1];
			};
		};

	};
};
true
