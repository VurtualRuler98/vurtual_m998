_par = params [["_ply",objNull,[objNull]],["_angle",0,[0]],["_abs",false,[false]]];
if ((!_par) || !(local _ply) || (isNull _ply) || !(vehicle _ply isKindOf "vurtual_hmmwv_base")) exitWith {false};
_veh = vehicle _ply;
_role = assignedVehicleRole _ply;
_angle=_angle/360;
if (_role select 0 != "Turret") exitWith {false};
if ((_role select 1 select 0 != 0) || !(isTurnedOut _ply)) exitWith {false};
if !(_abs) then {
	/*_oldAngle = _veh animationSourcePhase "gunnerTurnAround";
	if ((_oldAngle mod 1) != _oldAngle) then { //we went 360 degrees
		_oldAngle = _oldAngle mod 1; //remove the 360 from our angle
		_veh animateSource ["gunnerTurnAround",_oldAngle,true]; //instantly jump to the same angle, but sans the 360 degree spin
	};*/
	_angle=_angle+_oldAngle;
};
_angle = (round (_angle*6))/6; //round off our angle so we're always at a whole fraction
_veh animateSource ["gunnerTurnAround",_angle];
false
