_par = params [["_veh",objNull,[objNull]],["_cargo",false,[false]],["_force",false,[false]]];
if ((!_par) || (isNull _veh) || !(_veh isKindOf "vurtual_hmmwv_base")) exitWith {false};

_bedseats = getArray (configFile >> "CfgVehicles" >> (typeOf (_veh)) >> "VIVPassengers");

if (!_force && !_cargo && (count getVehicleCargo (_this select 0)>0)) exitWith {hint "Cargo bed must be empty.";false};
if (!_force && _cargo && ({(alive (_x select 0)) && ((_x select 2) in _bedseats)} count fullCrew [(_this select 0), "",true])>0) exitWith {hint "Cargo bed must be empty.";false};
(_this select 0) enableVehicleCargo _cargo;
{(_this select 0) lockCargo [_x,_cargo];} forEach _bedseats;
(_this select 0) animateSource ["bedseat_fold",parseNumber _cargo,_force];
true
