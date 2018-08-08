_par = params [["_veh",objNull,[objNull]]];
if ((!_par) || (isNull _veh) || !(_veh isKindOf "vurtual_hmmwv_base") || !(alive _veh)) exitWith {false};
_veh addAction ["Passenger mode",{[(_this select 0),false,false] call vurtual_m998_fnc_cargobed;},[],1.5,false,true,"","(alive _target) && (vehicle _this == _this) && (count getVehicleCargo _target)==0 && (vehicleCargoEnabled _target)",15,false,"tailgate"];
_veh addAction ["VIV Cargo mode",{[(_this select 0),true,false] call vurtual_m998_fnc_cargobed;},[],1.5,false,true,"","(alive _target) && (vehicle _this == _this) && !(vehicleCargoEnabled _target)",15,false,"tailgate"];
_veh addAction ["Raise/Lower tailgate",{(_this select 0) animateDoor ["tailgate_fold",(abs (((_this select 0) animationSourcePhase "tailgate_fold")-1))];},[_x select 1],1.5,false,true,"","(alive _target) && (vehicle _this == _this)",5,false,"tailgate"];
_veh addAction ["Passenger mode",{[(_this select 0),false,false] call vurtual_m998_fnc_cargobed;},[],1.5,false,true,"","(alive _target) && (driver _target == _this) && (count getVehicleCargo _target)==0 && (vehicleCargoEnabled _target)",15,false];
_veh addAction ["VIV Cargo mode",{[(_this select 0),true,false] call vurtual_m998_fnc_cargobed;},[],1.5,false,true,"","(alive _target) && (driver _target == _this) && !(vehicleCargoEnabled _target)",15,false];
true
