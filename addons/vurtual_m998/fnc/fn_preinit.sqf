["vurtual_m998_fording_damage","CHECKBOX",["(M998) Enable extended fording damage","If checked, exceeding the safe fording depth or exceeding 20km/h fording will slowly damage the engine, and submerging the exhaust with the engine off will kill it. Disabled, only submerging the intake will kill the engine."],"Vurtual's Vehicles",false,true] call CBA_settings_fnc_init;
["vurtual_m998","turret_left","Turret FFV Turn Left",{
	[player,60,false] call vurtual_m998_fnc_turnffv;
},"",[30,[false,false,false]],false,0,false] call cba_fnc_addkeybind; //A
["vurtual_m998","turret_right","Turret FFV Turn Right",{
	[player,-60,false] call vurtual_m998_fnc_turnffv;
},"",[32,[false,false,false]],false,0,false] call cba_fnc_addkeybind; //D
true