_par = params [["_veh",objNull,[objNull]],["_dmg",0,[0]]];
if ((!_par) || (isNull _veh) || !(_veh isKindOf "vurtual_hmmwv_base") || !(alive _veh)) exitWith {-1};

_armor = _veh getVariable ["vurtual_hmmwv_armor",0];
_bonusdmg = 4*_dmg*(1-_armor);
_hits = (getAllHitPointsDamage _veh) select 2;
_veh setDamage (damage _veh)+_bonusdmg;
{_veh setHitIndex [_forEachIndex,_x]} forEach _hits;
_bonusdmg
