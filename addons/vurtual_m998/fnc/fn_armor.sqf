_par = params [["_veh",objNull,[objNull]]];
if ((!_par) || (isNull _veh) || !(_veh isKindOf "vurtual_hmmwv_base") || !(alive _veh)) exitWith {false};
_hitARockerL = (1-(_veh getHitPointDamage "HitARockerL"))*0.02;
_hitARockerR = (1-(_veh getHitPointDamage "HitARockerR"))*0.02;
_hitAWindscreen = (1-(_veh getHitPointDamage "HitAWindscreen"))*0.2;
_hitAUnderbody = (1-(_veh getHitPointDamage "HitAUnderBody"))*0.2;
if (_veh animationSourcePhase "armor_akit_hide"==1) then {
	_hitAUnderbody = 0;
	_hitAWindscreen = 0;
	_hitARockerL = 0;
	_hitARockerR = 0;
};

_hitDoorL = (1-(_veh getHitPointDamage "HitDoorL"))*0.09;
_hitDoorR = (1-(_veh getHitPointDamage "HitDoorR"))*0.05; //4% blast protection lost for half door
_hitDoorL2 = (1-(_veh getHitPointDamage "HitDoorL2"))*0.09;
_hitDoorR2 = (1-(_veh getHitPointDamage "HitDoorR2"))*0.09;
if (_veh animationSourcePhase "door_hide"==1) then {
	_hitDoorL = 0;
	_hitDoorR = 0;
	_hitDoorL2 = 0;
	_hitDoorR2 = 0;
};

_hitARoof = (1-(_veh getHitPointDamage "HitARoof"))*0.1;
if (_veh animationSourcePhase "armor_roof_hide"==1) then {
	_hitARoof = 0;
};

_hitACargoL = (1-(_veh getHitPointDamage "HitACargoL"))*0.02; //imperfect blast protection
_hitACargoR = (1-(_veh getHitPointDamage "HitACargoR"))*0.02; //doesn't total 10%
if (_veh animationSourcePhase "armor_cargo_hide"==1) then {
	_hitACargoL = 0;
	_hitACargoR = 0;
};

_hitATailgate = (1-(_veh getHitPointDamage "HitATailgate"))*0.02;
if (_veh animationSourcePhase "armor_tailgate_hide"==1) then {
	_hitATailgate = 0;
};
//hypothetical hit-rear: 0.1

_armor = _hitATailgate+_hitACargoL+_hitACargoR+_hitARoof+_hitDoorL+_hitDoorL2+_hitDoorR+_hitDoorR2+_hitARockerR+_hitArockerL+_hitAUnderbody+_hitAWindscreen;
_armor = _armor^2;
_veh setVariable ["vurtual_hmmwv_armor",_armor];
true
