
#define true	1
#define false	0

#define private		0
#define protected		1
#define public		2

#define TEast		0
#define TWest		1
#define TGuerrila		2
#define TCivilian		3
#define TSideUnknown		4
#define TEnemy		5
#define TFriendly		6
#define TLogic		7

#define WHEEL_STRENGTH 10
#define WHEEL_DAMPER 3
#define WHEEL_SPRINGS(MASS,WHEELS,STRENGTH,DAMPER) sprungMass = MASS/WHEELS; \
springStrength = (MASS/WHEELS)*STRENGTH^2; \
springDamperRate = DAMPER*2*((MASS/WHEELS)*STRENGTH^2*(MASS/WHEELS))^0.5;


enum {
	DESTRUCTENGINE = 2,
	DESTRUCTDEFAULT = 6,
	DESTRUCTWRECK = 7,
	DESTRUCTTREE = 3,
	DESTRUCTTENT = 4,
	STABILIZEDINAXISX = 1,
	STABILIZEDINAXESXYZ = 4,
	STABILIZEDINAXISY = 2,
	STABILIZEDINAXESBOTH = 3,
	DESTRUCTNO = 0,
	STABILIZEDINAXESNONE = 0,
	DESTRUCTMAN = 5,
	DESTRUCTBUILDING = 1,
};

class DefaultEventhandlers;	// External class reference

class CfgPatches {
	class vurtual_m998_cargo {
		units[] = {
		"vurtual_m998",
		"vurtual_m998_4door",
		"vurtual_m1097",
		"vurtual_m1097a2",
		"vurtual_m1097a2_4door",
		"vurtual_m1113"
		};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"cba_main","A3_Soft_F","vurtual_m998"};
	};
};




class CfgVehicles {
	class Car;
	class Car_F: Car {
		class VehicleTransport;
	};
	class vurtual_hmmwv_base: Car_F {
		class VehicleTransport: VehicleTransport {
			class Cargo;
			class Carrier;
		};
		class complexGearbox;
	};
	class vurtual_hmmwv_base_4door;
	class vurtual_hmmwv_base_a1;
	class vurtual_hmmwv_base_a2: vurtual_hmmwv_base_a1 {
		class animationSources;
	};
	class vurtual_hmmwv_base_a2_4door: vurtual_hmmwv_base_a2 {
		class animationSources: animationSources {
			class Seats_A2;
			class door_hide;
			class bedseat_fold;
		};
	};
	class vurtual_hmmwv_base_ecv;
	class vurtual_m998: vurtual_hmmwv_base {
		model = "\vurtual_m998_cargo\vurtual_m998.p3d";
		scope = 2;
		displayName = "HMMWV M998";
	};
	class vurtual_m998_4door: vurtual_hmmwv_base_4door {
		model = "\vurtual_m998_cargo\vurtual_m998_4door.p3d";
		scope = 2;
		displayName = "HMMWV M998 (4 Door)";
	};
	class vurtual_m1097: vurtual_hmmwv_base {
		scope = 1;
		displayName = "HMMWV M1097";
		class VehicleTransport: VehicleTransport {
			class Cargo: Cargo {};
			class Carrier: Carrier {
				maxLoadMass = 2000;
			};
		};
		class complexGearbox: complexGearbox {
				TransmissionRatios[] = {"High", 1*1.92*2.73};
		};
	};
	class vurtual_m1097a2: vurtual_hmmwv_base_a2 {
		scope = 2;
		displayName = "HMMWV M1097A2";
		model = "\vurtual_m998_cargo\vurtual_m998.p3d";
		vurtual_hmmwv_addweight = 226;
	};
	class vurtual_m1097a2_4door: vurtual_hmmwv_base_a2_4door {
		scope = 2;
		displayName = "HMMWV M1097A2 (4 Door)";
		model = "\vurtual_m998_cargo\vurtual_m998_4door.p3d";
		class AnimationSources: AnimationSources {
			class Seats_A2: Seats_A2 {
				initPhase = 1;
			};
			class door_hide: door_hide {};
			class bedseat_fold: bedseat_fold {};
		};
		vurtual_hmmwv_addweight = 226;
	};
	class vurtual_m1113: vurtual_hmmwv_base_ecv {
		scope = 2;
		displayName = "HMMWV M1113 ECV";
		model = "\vurtual_m998_cargo\vurtual_m1113.p3d";
	};
};
	