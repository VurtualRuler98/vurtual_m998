
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
	class vurtual_m998 {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"cba_main","A3_Soft_F"};
	};
};

class CfgFunctions {
	
	class vurtual_m998 {
		tag = "vurtual_m998";
		class vurtual_m998Functions {
			file = "\vurtual_m998\fnc";
			class init {};
			class passenger {};
			class cargobed {};
			class preinit {};
		};
	};
};
class CBA_Extended_EventHandlers_base;
class Extended_Preinit_EventHandlers {
	class vurtual_m998_preinit {
		init = "call vurtual_m998_fnc_preinit";
	};
};
class WeaponFireGun;	// External class reference
class WeaponCloudsGun;	// External class reference
class WeaponFireMGun;	// External class reference
class WeaponCloudsMGun;	// External class reference
class RCWSOptics;	// External class reference

class CfgMovesBasic {
	class DefaultDie;	// External class reference
	
	class ManActions {
		vurtual_m998_Driver = "vurtual_m998_Driver";
		vurtual_m998_Gunner03 = "vurtual_m998_Gunner03";
	};
};

class CfgMovesMaleSdr : CfgMovesBasic {
	class States {
		class Crew;	// External class reference
		class AmovPercMstpSnonWnonDnon;	// External class reference
		
		class vurtual_KIA_HMMWV_Driver : DefaultDie {
			actions = "DeadActions";
			file = "\vurtual_m998\Anim\KIA_HMMWV_Driver.rtm";
			speed = 0.5;
			looped = "false";
			terminal = true;
			connectTo[] = {"Unconscious", 0.1};
			soundEnabled = false;
		};
		
		class vurtual_m998_Driver : Crew {
			file = "\vurtual_m998\Anim\HMMWV_Driver.rtm";
			interpolateTo[] = {"vurtual_KIA_HMMWV_Driver", 1};
			leftHandIKCurve[] = {1};
			rightHandIKCurve[] = {1};
		};
	};
};

class CfgVehicles {
	class LandVehicle;	// External class reference
	
	class Car : LandVehicle {
		class NewTurret;	// External class reference
	};
	
	class Car_F : Car {
		class AnimationSources;	// External class reference
		class CargoTurret;
		class Turrets {
			class MainTurret : NewTurret {};
			class ViewOptics;	// External class reference
		};
		
		class HitPoints {
			class hitEngine;
			class HitLFWheel;	// External class reference
			class HitLF2Wheel;	// External class reference
			class HitRFWheel;	// External class reference
			class HitRF2Wheel;	// External class reference
			class HitGlass1;	// External class reference
			class HitGlass2;	// External class reference
			class HitGlass3;	// External class reference
			class HitGlass4;	// External class reference
			class HitGlass5;	// External class reference
			class HitGlass6;	// External class reference
		};
	};
	
	class vurtual_hmmwv_base: Car_F { 
		cargoIsCoDriver[] = {0};
		cargoProxyIndexes[] = {2,3,4,5,6,7};
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment2"};
		class SpeechVariants {
			class Default {
				speechSingular[] = {"veh_vehicle_car_s"};
				speechPlural[] = {"veh_vehicle_car_p"};
			};
		};
		
		class AnimationSources: AnimationSources {
			class gmv_hide_radio {
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
				displayName = "Hide radio";
				forceAnimatePhase = 1;
				forceAnimate[] = {"gmv_hide_bft",1};
			};
			class gmv_hide_bft {
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
				displayName = "Hide BFT";
				forceAnimatePhase = 0;
				forceAnimate[] = {"gmv_hide_radio",0};
			};
			class gmv_hide_bumper {
				source = "user";
				initPhase = 0;
				animPeriod = 0.01;
				displayName = "Hide Bumper";
			};
			class door_hide {
				displayName = "Remove doors";
				source = "door";
				initPhase = 0;
				animPeriod = 0.01;
				onPhaseChanged = "{(_this select 0) animateDoor [_x,(_this select 1)]} forEach ['window_codriver','window_left','window_right','door_hide']";
			}
			/*
			class door_stored {
				displayName = "Add stowed doors";
				source = "door";
				initPhase = 0;
				animPeriod = 0.01;
				onPhaseChanged = "{(_this select 0) animateDoor [_x,(_this select 1)]} forEach ['door_hide','window_codriver','window_left','window_right','door_stored']";
			};
			*/
			class blackout_hide {
				displayName = "Turn blackout lights off";
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
				forceAnimatePhase = 0;
				forceAnimate[] = {"brakelight_normal_hide",1};
			};
			class brakelight_normal_hide {
				displayName = "Turn normal brake lights off";
				source = "user";
				initPhase = 0;
				animPeriod = 0.01;
				forceAnimatePhase = 0;
				forceAnimate[] = {"blackout_hide",1};
			};
			class bedseat_fold {
				lockCargo[] = {1,2,3,4,5,6,7,8,9};
				lockCargoAnimationPhase = 1;
				source = "user";
				initPhase = 0;
				animPeriod = 1;
				displayName = "Enable cargo mode";
				onPhaseChanged = "(_this select 0) enableVehicleCargo ((_this select 1)==1); (_this select 0) animateSource ['bedseat_fold',(_this select 1),true];";
			};
			class Door_Left {
				source = "door";
				initPhase = 0;
				animPeriod = 0.4;
			};
			class Door_Right: Door_Left {
			};
			class tailgate_fold {
				source = "door";
				initPhase = 0;
				animPeriod = 0.5;
				//displayName = "Lower tailgate";
				//onPhaseChanged = "(_this select 0) animateDoor ['tailgate_fold',(_this select 1),true]";
			};
			class fordingkit_hide {
				source = "user";
				initPhase = 0;
				animPeriod = 0.1;
				displayName = "Remove fording kit";
				onPhaseChanged = "(_this select 0) animateSource ['fordingkit_hide',(_this select 1),true]";
			};
			class Seats_A1 {
				source = "user";
				initPhase = 0;
				animPeriod = 0.1;
				displayName = "Install A1 seats";
				onPhaseChanged = "(_this select 0) animateSource ['Seats_A1',(_this select 1),true]";
			};
			class Bumper_A2 {
				source = "user";
				initPhase = 0;
				animPeriod = 0.1;
			};
			class window_codriver {
				source = "door";
				initPhase = 0;
				animPeriod = 0.5;
			};
		};
		animationList[] =  {"bedseat_fold",0};
		VIVPassengers[] = {1,2,3,4,5,6,7,8,9}; //0 is front passenger, 1 and 2 are cargoTurret
		tf_RadioType = "tf_rt1523g";
		tf_hasLRradio = 1;
		tf_isolatedAmount = 0.1;
		tf_range=40000;
		maxSpeed = 105;
		slowSpeedForwardCoef = 0.15;
		normalSpeedForwardCoef = 0.84;
		acceleration = 15;
		textSingular = "$STR_A3_nameSound_veh_vehicle_armedcar_s";
		textPlural = "$STR_A3_nameSound_veh_vehicle_armedcar_p";
		nameSound = "veh_vehicle_armedcar_s";
		author = "$STR_A3_Bohemia_Interactive";
		_generalMacro = "hmmwv";
		scope = private;
		Model = "\vurtual_m998\vvurtual_m998.p3d";
		Picture = "vurtual_m998\Data\hmmwv_ca.paa";
		Icon = "vurtual_m998\Data\icomap_hmwv_ca.paa";
		mapSize = 6;
		displayName = "M1151 (M2)";
		crew = "B_Soldier_F";
		typicalCargo[] = {"B_Soldier_F", "B_Soldier_F", "B_Soldier_F", "B_Soldier_F"};
		side = TWest;
		faction = BLU_F;
		wheelCircumference = 2.834;
		antiRollbarForceCoef = 12;
		antiRollbarForceLimit = 10;
		antiRollbarSpeedMin = 20;
		antiRollbarSpeedMax = 50;
		crewVulnerable = true;
		crewCrashProtection = 0.85;
		weapons[] = {"TruckHorn2"};
		magazines[] = {};
		damperSize = 0.2;	// max. damper amplitude
		damperForce = 1;	// larger number more stiffness dampers
		damperDamping = 1;	// larger number less movement in dampers
		armor = 150;
		armorStructural = 4;
		turnCoef = 2.5;
		steerAheadPlan = 0.2;
		steerAheadSimul = 0.4;
		predictTurnPlan = 0.9;
		predictTurnSimul = 0.5;
		brakeDistance = 1.0;	// vehicle movement precision
		terrainCoef = 1.5;
		wheelDamageThreshold = 0.7;
		wheelDestroyThreshold = 0.99;
		wheelDamageRadiusCoef = 0.95;
		wheelDestroyRadiusCoef = 0.45;
		cost = 200000;
		precision = 15;
		armorGlass = 0.99;
		armorWheels = 0.8;
		soundServo[] = {"A3\sounds_f\dummysound", db-40, 1.0, 10};
		soundEnviron[] = {"", db-5, 1};
		transportMaxBackpacks = 25;
		transportSoldier = 6;
		
		castDriverShadow = "false";
		driverAction = "vurtual_m998_Driver";
		cargoAction[] = {"passenger_low01"};
		
		accuracy = 0.32;	// accuracy needed to recognize type of this target
		
		// threat (VSoft, VArmor, VAir), how threatening vehicle is to unit types
		threat[] = {0, 0, 0};

		driverLeftHandAnimName = "";
		driverRightHandAnimName = "";
		
		class TransportMagazines {};
		
		class TransportItems {};
		
		class TransportWeapons {};

		brakeIdleSpeed = 1.78;
		fuelCapacity = 95;
		
	
		simulation = "carx";
		dampersBumpCoef = 6.0;
		differentialType = "all_limited";
		frontRearSplit = 0.5;
		frontBias = 1.3;
		rearBias = 1.3;
		centreBias = 1.3;
		clutchStrength = 20.0;
		dampingRateFullThrottle = 0.08;
		dampingRateZeroThrottleClutchEngaged = 2.0;
		dampingRateZeroThrottleClutchDisengaged = 0.35;
		
		class Wheels {
			class LF {
				boneName = "wheel_1_1_damper";
				steering = 1;
				side = "left";
				center = "wheel_1_1_axis";
				boundary = "wheel_1_1_bound";
				width = 0.126;
				mass = 30;
				MOI = 12.8;
				dampingRate = 0.1;
				maxBrakeTorque = 10000;
				maxHandBrakeTorque = 0;
				suspTravelDirection[] = {0, -1, 0};
				suspForceAppPointOffset = "wheel_1_1_axis";
				tireForceAppPointOffset = "wheel_1_1_axis";
				maxCompression = 0.05;
				mMaxDroop = 0.1;
				WHEEL_SPRINGS(3500,4,WHEEL_STRENGTH,WHEEL_DAMPER)
				longitudinalStiffnessPerUnitGravity = 8000;
				latStiffX = 25;
				latStiffY = 180;
				frictionVsSlipGraph[] = {{0, 1}, {0.5, 1}, {1, 1}};
			};
			class LR: LF {
				boneName = "wheel_1_2_damper";
				steering = 0;
				center = "wheel_1_2_axis";
				boundary = "wheel_1_2_bound";
				suspForceAppPointOffset = "wheel_1_2_axis";
				tireForceAppPointOffset = "wheel_1_2_axis";
				maxHandBrakeTorque = 3500;
			};
			class RF: LF {
				boneName = "wheel_2_1_damper";
				center = "wheel_2_1_axis";
				boundary = "wheel_2_1_bound";
				suspForceAppPointOffset = "wheel_2_1_axis";
				tireForceAppPointOffset = "wheel_2_1_axis";
				steering = 1;
				side = "right";
			};
			class RR: RF {
				boneName = "wheel_2_2_damper";
				steering = 0;
				center = "wheel_2_2_axis";
				boundary = "wheel_2_2_bound";
				suspForceAppPointOffset = "wheel_2_2_axis";
				tireForceAppPointOffset = "wheel_2_2_axis";
				maxHandBrakeTorque = 3500;
			};
		};
		attenuationEffectType = "OpenCarAttenuation";
		soundAttenuationCargo[] = {1,0};
		soundGetIn[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\getin", db-5, 1};
		soundGetOut[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\getout", db-5, 1, 40};
		soundDammage[] = {"", 0.562341, 1};
		soundEngineOnInt[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_int_start", 0.354813, 1.0};
		soundEngineOnExt[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_ext_start", 0.707946, 1.0, 200};
		soundEngineOffInt[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_int_stop", 0.354813, 1.0};
		soundEngineOffExt[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_ext_stop", 0.707946, 1.0, 200};
		buildCrash0[] = {"A3\sounds_f\Vehicles\soft\noises\crash_building_01", 1.0, 1, 200};
		buildCrash1[] = {"A3\sounds_f\Vehicles\soft\noises\crash_building_02", 1.0, 1, 200};
		buildCrash2[] = {"A3\sounds_f\Vehicles\soft\noises\crash_building_03", 1.0, 1, 200};
		buildCrash3[] = {"A3\sounds_f\Vehicles\soft\noises\crash_building_04", 1.0, 1, 200};
		soundBuildingCrash[] = {"buildCrash0", 0.25, "buildCrash1", 0.25, "buildCrash2", 0.25, "buildCrash3", 0.25};
		WoodCrash0[] = {"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_01", 1.0, 1, 200};
		WoodCrash1[] = {"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_02", 1.0, 1, 200};
		WoodCrash2[] = {"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_03", 1.0, 1, 200};
		WoodCrash3[] = {"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_04", 1.0, 1, 200};
		WoodCrash4[] = {"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_05", 1.0, 1, 200};
		WoodCrash5[] = {"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_06", 1.0, 1, 200};
		soundWoodCrash[] = {"woodCrash0", 0.166, "woodCrash1", 0.166, "woodCrash2", 0.166, "woodCrash3", 0.166, "woodCrash4", 0.166, "woodCrash5", 0.166};
		ArmorCrash0[] = {"A3\sounds_f\Vehicles\soft\noises\crash_vehicle_01", 1.0, 1, 200};
		ArmorCrash1[] = {"A3\sounds_f\Vehicles\soft\noises\crash_vehicle_02", 1.0, 1, 200};
		ArmorCrash2[] = {"A3\sounds_f\Vehicles\soft\noises\crash_vehicle_03", 1.0, 1, 200};
		ArmorCrash3[] = {"A3\sounds_f\Vehicles\soft\noises\crash_vehicle_04", 1.0, 1, 200};
		soundArmorCrash[] = {"ArmorCrash0", 0.25, "ArmorCrash1", 0.25, "ArmorCrash2", 0.25, "ArmorCrash3", 0.25};
		#include "legacySounds.hpp"

		
		class Exhausts {
			class Exhaust1 {
				position = "vyfuk start";
				direction = "vyfuk konec";
				effect = "ExhaustEffectOffroad";
			};
		};
		class Turrets: Turrets {
			class CargoTurret_CoDriver: CargoTurret {
				gunnerDoor = "door_right";
				gunnerAction = "passenger_inside_2";
				gunnerInAction = "passenger_low01";
				memoryPointsGetInGunner = "pos codriver";
				memoryPointsGetInGunnerDir = "pos codriver dir";
				gunnerName = "Front passenger";
				gunnerCompartments = "Compartment1";
				ProxyIndex=1;
				isPersonTurret = 1;
				forceHideGunner = 0;
				maxElev = 45;
				minElev = -45;
				maxTurn = -30;
				minTurn = -105;
				stabilizedInAxes = 0;
				enabledByAnimationSource = "window_codriver";
				commanding = 1;
				soundAttenuationTurret = "OpenCarAttenuation";
				disableSoundAttenuation = 0;
			};
			class CargoTurret_tailgate_L: CargoTurret {
				gunnerDoor = "tailgate_fold";
				gunnerAction = "passenger_inside_2";
				gunnerInAction = "passenger_inside_2"; //fixes standing up in steat
				memoryPointsGetInGunner = "pos cargo";
				memoryPointsGetInGunnerDir = "pos cargo dir";
				gunnerName = "Passenger (Tailgate Left)";
				gunnerCompartments = "Compartment2";
				proxyIndex = 9;
				isPersonTurret = 1;
				forceHideGunner=1; //fixes being turned out in seat
				maxElev = 75;
				minElev = -30;
				maxTurn = 15;
				minTurn = -95;
				stabilizedInAxes=0;
				commanding = 1; //fixes seat switching
			};
			class CargoTurret_Tailgate_R: CargoTurret_Tailgate_L {
				memoryPointsGetInGunner = "pos tailgate";
				memoryPointsGetInGunnerDir = "pos tailgate dir";
				proxyIndex = 8;
				maxTurn = 95;
				minTurn = -15;
				gunnerName = "Passenger (Tailgate Right)";
			};
		};
		driverDoor = "door_left";
		cargoDoors[] = {"tailgate_fold"};
		hiddenSelections[] = {"Camo", "Camo1", "Camo2", "Camo3", "Camo4","Camo5","CamoWheel"};
		hiddenSelectionsTextures[] = {"\vurtual_m998\Data\hmmwv_body_canvas_1_co.paa", "\vurtual_m998\data\hmmwv_hood_canvas_co.paa", "\vurtual_m998\data\hmmwv_regular_1_co.paa", "\vurtual_m998\data\hmmwv_parts_1_ca.paa","vurtual_m998\data\hmmwv_canvas_1_co.paa","\vurtual_m998\data\hmmwv_troopseat_sand_co.paa","\vurtual_m998\data\hmmwv_oldwheel_co.paa"};
		class textureSources {
			class woodland_old {
				displayname = "Woodland (Worn)";
				author = "vurtual";
				textures[] = {"\vurtual_m998\Data\hmmwv_body_canvas_1_wl_co.paa", "\vurtual_m998\data\hmmwv_hood_canvas_wl_co.paa", "\vurtual_m998\data\hmmwv_regular_wl_1_co.paa", "\vurtual_m998\data\hmmwv_parts_wl_1_ca.paa","vurtual_m998\data\hmmwv_canvas_1_green_co.paa","\vurtual_m998\data\hmmwv_troopseat_green_co.paa"};
				factions[] = {};
			};
			class green {
				displayname = "Green";
				author = "vurtual";
				textures[] = {"\vurtual_m998\Data\hmmwv_body_canvas_1_green_co.paa", "\vurtual_m998\data\hmmwv_hood_canvas_green_co.paa", "\vurtual_m998\data\hmmwv_regular_1_green_co.paa", "\vurtual_m998\data\hmmwv_parts_1_green_ca.paa","vurtual_m998\data\hmmwv_canvas_1_green_co.paa","\vurtual_m998\data\hmmwv_troopseat_green_co.paa"};
				factions[] = {};
			};
			class desert {
				displayname = "Desert";
				author = "vurtual";
				textures[] = {"\vurtual_m998\Data\hmmwv_body_canvas_1_co.paa", "\vurtual_m998\data\hmmwv_hood_canvas_co.paa", "\vurtual_m998\data\hmmwv_regular_1_co.paa", "\vurtual_m998\data\hmmwv_parts_1_ca.paa","vurtual_m998\data\hmmwv_canvas_1_co.paa","\vurtual_m998\data\hmmwv_troopseat_sand_co.paa"};
				factions[] = {};
			};
		};
		class HitPoints : HitPoints {
			class HitGlass1 : HitGlass1 {
				armor = 0.1;
			};
			
			class HitGlass2 : HitGlass2 {
				armor = 0.1;
			};
			
			class HitGlass3 : HitGlass3 {
				armor = 0.1;
				//convexComponent = "glass3_door";
				visual = "glass3_door";
			};
			
			class HitGlass4 : HitGlass4 {
				armor = 0.1;
				//convexComponent = "glass4_door";
				visual = "glass4_door";
			};
			
			class HitLFWheel : HitLFWheel {
				armor = 0.8;
			};
			
			class HitLBWheel : HitLF2Wheel {
				armor = 0.8;
			};
			
			class HitRFWheel : HitRFWheel {
				armor = 0.8;
			};
			
			class HitRBWheel : HitRF2Wheel {
				armor = 0.8;
			};
			
			class HitFuel {
				armor = 1.4;
				material = -1;
				name = "palivo";
				visual = "";
				passThrough = true;
			};
		};
		
		class Damage {
			tex[] = {};
			mat[] = {
				"vurtual_m998\Data\hmmwv_glass.rvmat",
				"A3\data_f\Glass_veh_damage.rvmat",
				"A3\data_f\Glass_veh_damage.rvmat",
				
				"vurtual_m998\Data\hmmwv_body_1.rvmat",
				"vurtual_m998\Data\hmmwv_body_damage.rvmat",
				"vurtual_m998\Data\hmmwv_body_destruct.rvmat",
				
				"vurtual_m998\Data\hmmwv_details.rvmat",
				"vurtual_m998\Data\hmmwv_details_damage.rvmat",
				"vurtual_m998\Data\hmmwv_details_destruct.rvmat"
			};
		};
		
		class Reflectors {
			class LightCarHeadL01 {
				color[] = {1900, 1800, 1700};
				ambient[] = {5, 5, 5};
				position = "LightCarHeadL01";
				direction = "LightCarHeadL01_end";
				hitpoint = "Light_L";
				selection = "Light_L";
				size = 1;
				innerAngle = 100;
				outerAngle = 179;
				coneFadeCoef = 10;
				intensity = 1;
				useFlare = 1;
				dayLight = 0;
				flareSize = 1;
				
				class Attenuation {
					start = 1;
					constant = 0;
					linear = 0;
					quadratic = 0.25;
					hardLimitStart = 30;
					hardLimitEnd = 60;
				};
			};
			
			class LightCarHeadL02 : LightCarHeadL01 {
				position = "LightCarHeadL02";
				direction = "LightCarHeadL02_end";
				FlareSize = 0.5;
			};
			
			class LightCarHeadR01 : LightCarHeadL01 {
				position = "LightCarHeadR01";
				direction = "LightCarHeadR01_end";
				hitpoint = "Light_R";
				selection = "Light_R";
			};
			
			class LightCarHeadR02 : LightCarHeadR01 {
				position = "LightCarHeadR02";
				direction = "LightCarHeadR02_end";
				FlareSize = 0.5;
			};
		};
		aggregateReflectors[] = {{"Left", "Right", "Left2", "Right2"}};
		
		class RenderTargets {
			class LeftMirror {
				renderTarget = "rendertarget0";
				
				class CameraView1 {
					pointPosition = "PIP0_pos";
					pointDirection = "PIP0_dir";
					renderQuality = 2;
					renderVisionMode = 4;
					fov = 0.7;
				};
			};
			class RightMirror {
				renderTarget = "rendertarget2";
				
				class CameraView1 {
					pointPosition = "PIP2_pos";
					pointDirection = "PIP2_dir";
					renderQuality = 2;
					renderVisionMode = 4;
					fov = 0.7;
				};
			};
		};
		slingLoadCargoMemoryPoints[] = { "SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3","SlingLoadCargo4"};
		class VehicleTransport {
			class Cargo {
				dimensions[]				= {"VTV_Cargo_Base","VTV_Cargo_Corner"};
				parachuteClass				= "B_Parachute_02_F";
				canBeTransported            = 1;
				parachuteHeightLimit		= 10;
			};
			class Carrier {
				cargoBayDimensions[]        = {"VTV_Carrier_Base", "VTV_Carrier_Corner"};
				cargoSpacing[]              = {0, 0, 0};
				cargoAlignment[]            = {"front","left"};
				maxLoadMass                 = 1100; //1100kg 998, 2300kg ECV
				disableHeightLimit			= 1;
				exits[]						= {"VTV_exit_1"};
				unloadingInterval			= 2;
				loadingDistance				= 0;
				loadingAngle				= 0;
				parachuteClassDefault       = "B_Parachute_02_F";
				parachuteHeightLimitDefault = 10000;
			};
		};
		maxFordingDepth=1000; //no kit: 0.76m safe, 1.3m kill. kit: 1.5m safe, 1.9m kill.
		hasGunner = false;
		class EventHandlers {
			init = "[_this select 0] call vurtual_m998_fnc_init";
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
		//3-speed transmission
		class complexGearbox {
				GearboxRatios[] = {"R1", -2.08, "N", 0, "D1", 2.48, "D2", 1.48, "D3", 1};
				//TransmissionRatios[] = {"High", 1*1.92*2.56};
				TransmissionRatios[] = {"High", 1*1.92*2.65};
				gearBoxMode = "auto";
				moveOffGear = 1;
				driveString = "D";
				neutralString = "N";
				reverseString = "R";
		};
		idleRpm = 650;
		redRpm = 3600;
		enginePower = 123;
		maxOmega = 377;
		peakTorque = 352;
		torqueCurve[] = {
			{0.0, "18/24"},
			{"16/36", "23/24"},
			{"20/36", "23.5/24"},
			{"21/36", "24/24"},
			{"24/36", "23.5/24"},
			{"28/36", "23.2/24"},
			{"30/36", "23/24"},
			{"36/36", "21/24"}
		};
		//changeGearMinEffectivity[] = {0.95, 0.15, 0.95, 0.95, 0.95};
		changeGearOmegaRatios[] = {
			36/36, 5/36, //R
			14/36, 0, //N
			28/36, 5/36, //1
			24/36, 16/36, //2
			37/36, 16/36 //3
		};
		changeGearType = "rpmratio";
		switchTime = 0.11;
		latency = 0.5;
	};
	class vurtual_hmmwv_base_4door: vurtual_hmmwv_base {
			#include "4door.hpp"
	};
	class vurtual_hmmwv_base_a1: vurtual_hmmwv_base {
		hiddenSelections[] = {"Camo", "Camo1", "Camo2", "Camo3", "Camo4","Camo5","CamoWheel"};
		hiddenSelectionsTextures[] = {"\vurtual_m998\Data\hmmwv_body_canvas_1_co.paa", "\vurtual_m998\data\hmmwv_hood_canvas_co.paa", "\vurtual_m998\data\hmmwv_regular_1_co.paa", "\vurtual_m998\data\hmmwv_parts_1_ca.paa","vurtual_m998\data\hmmwv_canvas_1_co.paa","\vurtual_m998\data\hmmwv_troopseat_sand_co.paa","\vurtual_m998\data\hmmwv_details_co.paa"};
		class AnimationSources: AnimationSources {
			class Seats_A1: Seats_A1 {
				initPhase = 1;
			};
			class door_hide: door_hide {};
			class bedseat_fold: bedseat_fold {};
		};
	};
	class vurtual_hmmwv_base_a2: vurtual_hmmwv_base_a1 {
		//4-speed transmission
		class complexGearbox: complexGearbox {
				GearboxRatios[] = {"R1", -2.08, "N", 0, "D1", 2.48, "D2", 1.48, "D3", 1, "D4", 0.75};
				TransmissionRatios[] = {"High", 1*1.92*2.73};
		};
		//A2 cargo capacity
		class VehicleTransport: VehicleTransport {
			class Cargo: Cargo {
				dimensions[]				= {"VTV_Cargo_Base_A2","VTV_Cargo_Corner"};
			};
			class Carrier: Carrier {
				maxLoadMass = 2000;
			};
		};
		class Wheels: Wheels {
			class LF: LF {
				WHEEL_SPRINGS(4700,4,WHEEL_STRENGTH,WHEEL_DAMPER)
			};
			class RF: RF {
				WHEEL_SPRINGS(4700,4,WHEEL_STRENGTH,WHEEL_DAMPER)
			};
			class LR: LR {
				WHEEL_SPRINGS(4700,4,WHEEL_STRENGTH,WHEEL_DAMPER)
			};
			class RR: RR {
				WHEEL_SPRINGS(4700,4,WHEEL_STRENGTH,WHEEL_DAMPER)
			};
		};
		idleRpm = 725;
		redRpm = 3400;
		maxOmega = 356;
		peakTorque = 393;
		torqueCurve[] = {
			{0.0, "28/43"},
			{"10/34", "32/43"},
			{"18/34", "43/43"},
			{"22/34", "40/43"},
			{"25/34", "37/43"},
			{"34/34", "30/43"}
		};
		//changeGearMinEffectivity[] = {0.95, 0.15, 0.95, 0.95, 0.95, 0.95};
		changeGearOmegaRatios[] = {
			34/34, 5/34, //R
			14/34, 0, //N
			26/34, 5/34, //1
			24/34, 15/34, //2
			22/34, 16/34, //3
			35/34, 16/34 //4
		};
		switchTime = 0.11;
		latency = 0.5;
		class AnimationSources: AnimationSources {
			class Bumper_A2: Bumper_A2 {
				initPhase = 1;
			};
			class door_hide: door_hide {};
			class bedseat_fold: bedseat_fold {};
		};
	};
	class vurtual_hmmwv_base_a2_4door: vurtual_hmmwv_base_a2 {
			#include "4door.hpp"
	};
	class vurtual_hmmwv_base_ecv: vurtual_hmmwv_base_a2 {
		enginePower = 142;
		class VehicleTransport: VehicleTransport {
			class Cargo: Cargo {};
			class Carrier: Carrier {
				maxLoadMass = 2300;
			};
		};
		class Wheels: Wheels {
			class LF: LF {
				WHEEL_SPRINGS(5220,4,WHEEL_STRENGTH,WHEEL_DAMPER)
			};
			class RF: RF {
				WHEEL_SPRINGS(5220,4,WHEEL_STRENGTH,WHEEL_DAMPER)
			};
			class LR: LR {
				WHEEL_SPRINGS(5220,4,WHEEL_STRENGTH,WHEEL_DAMPER)
			};
			class RR: RR {
				WHEEL_SPRINGS(5220,4,WHEEL_STRENGTH,WHEEL_DAMPER)
			};
		};
		hiddenSelections[] = {"Camo", "Camo1", "Camo2", "Camo3", "Camo4","Camo5","CamoWheel"};
		hiddenSelectionsTextures[] = {"\vurtual_m998\Data\hmmwv_body_canvas_1_co.paa", "\vurtual_m998\data\hmmwv_hood_canvas_co.paa", "\vurtual_m998\data\hmmwv_regular_1_co.paa", "\vurtual_m998\data\hmmwv_parts_1_ca.paa","vurtual_m998\data\hmmwv_canvas_1_co.paa","\vurtual_m998\data\hmmwv_troopseat_sand_co.paa","\vurtual_m998\data\hmmwv_ecvwheel_co.paa"};
		class AnimationSources: AnimationSources {
			class door_hide: door_hide {};
			class bedseat_fold: bedseat_fold {};
		};
		class Turrets: Turrets {
			class CargoTurret_CoDriver: CargoTurret_CoDriver {
			};
			class CargoTurret_Tailgate_L: CargoTurret_Tailgate_L {};
			class CargoTurret_Tailgate_R: CargoTurret_Tailgate_R {};
		};
	};
};
	