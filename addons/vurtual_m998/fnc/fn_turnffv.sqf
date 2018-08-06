_par = params [["_ply",objNull,[objNull]],["_angle",0,[0]],["_abs",false,[false]]];
if ((!_par) || !(local _ply) || (isNull _ply) || !(vehicle _ply isKindOf "vurtual_hmmwv_base")) exitWith {false};
_veh = vehicle _ply;
_role = assignedVehicleRole _ply;
_angle=_angle/360;
if (_role select 0 != "Turret") exitWith {false};
if ((_role select 1 select 0 != 0) || !(isTurnedOut _ply)) exitWith {false};
if !(_abs) then {
	_angle=_angle+(_veh animationSourcePhase "gunnerTurnAround");
};
_veh animateSource ["gunnerTurnAround",_angle];
false

