class CfgPatches {
	class vurtual_m998_gmv {
		units[] = {
		"vurtual_gmv",
		"vurtual_gmv_m2"
		};
		weapons[] = {
			"vurtual_mk19",
			"vurtual_m240_veh"
		};
		requiredVersion = 0.1;
		requiredAddons[] = {"cba_main","A3_Soft_F","vurtual_m998"};
	};
};
class WeaponCloudsMGun;
class cfgVehicles {
	class vurtual_hmmwv_base_a1;
	class vurtual_hmmwv_base_a2: vurtual_hmmwv_base_a1 {
		class animationSources;
		class Turrets;
	};
	class vurtual_hmmwv_base_ecv: vurtual_hmmwv_base_a2 {
		class animationSources: animationSources {
			class seats_A1;
			class door_hide;
			class bedseat_fold;
		};
		class Turrets: Turrets {
			class mainTurret;
			class CargoTurret_CoDriver;
			class CargoTurret_Passenger_L;
			class CargoTurret_Passenger_R;
			class CargoTurret_Tailgate_L;
			class CargoTurret_Tailgate_R;
		};
	};
	class vurtual_gmv: vurtual_hmmwv_base_ecv {
		driverAction = "vurtual_m998_Driver";
		driverInAction = "vurtual_m998_Driver";
		hideProxyInCombat = 1;
		forceHideDriver = 1;
		fuelCapacity = 95+56.7;
		scope = 2;
		displayName = "HMMWV M1113 GMV (Mk19)";
		vurtual_hmmwv_addweight = 0;
		model = "\vurtual_m998_gmv\vurtual_gmv.p3d";
		cargoCompartments[] = {"Compartment1"};
		transportSoldier = 0;
		VIVPassengers[] = {2,3,4,5};
		cargoIsCoDriver[] = {0};
		cargoProxyIndexes[] = {};
		soundAttenuationCargo[] = {0};
		cargoDoors[] = {"tailgate_fold"};
		class AnimationSources:AnimationSources
		{
			class ReloadAnim{source="reload";weapon="vurtual_mk19";};
			class ReloadMagazine{source="reloadmagazine";weapon="vurtual_mk19";};
			class Revolving{source="revolving";weapon="vurtual_mk19";};
			class ReloadAnim2{source="reload";weapon="vurtual_m240_veh";};
			class ReloadMagazine2{source="reloadmagazine";weapon="vurtual_m240_veh";};
			class Revolving2{source="revolving";weapon="vurtual_m240_veh";};
			class GunnerTurnOut {
				source = "door";
				initPhase = 0;
				animPeriod = 0.2;
			};
			class Seats_A1: Seats_A1{
				displayName = "";
			};
			class Door_Hide: Door_Hide {
				displayName = "";
			};
			class bedseat_fold: bedseat_fold {
				lockCargo[] = {2,3,4,5};
			};
			class gmv_hide_ammo {
				source = "user";
				initPhase = 0;
				animPeriod = 0.01;
				displayName = "Hide ammo boxes";
			};
			class gmv_hide_bags {
				source = "user";
				initPhase = 0;
				animPeriod = 0.01;
				displayName = "Hide bags";
			};
			class gmv_hide_weapon1 {
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
				displayName = "Hide Weapon 1";
			};
			class gmv_hide_weapon2 {
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
				displayName = "Hide Weapon 2";
			};
		};
		viewDriverInExternal=1;
		class Turrets: Turrets {
			class MainTurret: MainTurret {
				gunBeg = "usti hlavne";
				gunEnd = "konec hlavne";
				body = "MainTurret";
				gun = "MainGun";
				optics = 0;
				selectionFireAnim = "muzzleflash";
				weapons[]={"vurtual_mk19"};
				magazines[] = {"32Rnd_40mm_G_belt","32Rnd_40mm_G_belt","32Rnd_40mm_G_belt","32Rnd_40mm_G_belt","32Rnd_40mm_G_belt","32Rnd_40mm_G_belt","32Rnd_40mm_G_belt","32Rnd_40mm_G_belt"};
				soundServo[] = {"A3\sounds_f\dummysound", db-40, 1.0, 10};
				gunnerAction = "vehicle_passenger_stand_2";
				gunnerInAction = "gunner_standup01";
				viewGunnerInExternal = 1;
				castGunnerShadow = true;
				memoryPointGun="OtocHlaven";
				turretInfoType="RscOptics_Offroad_01";
				gunnerRightHandAnimName = "OtocHlaven";
				gunnerLeftHandAnimName = "OtocHlaven";
				class GunFire :WeaponCloudsMGun{interval = 0.01;};
				commanding = 0;
				personTurretAciton = "vehicle_passenger_stand_2";
				animationSourceHatch = "gunnerTurnOut";
				primaryGunner = 1;
				primaryObserver = 0;
				maxOutElev=45;
				allowLauncherOut=1;
				minOutElev=-20;
				minOutTurn=-121;
				maxOutTurn=179;
				outGunnerMayFire=0;
				isPersonTurret=1;
				gunnerName = "Gunner (Mk19)";
				inGunnerMayFire=1;
				
				LODOpticsIn = 1200;
				LODTurnedOut = 1200;
				LODTurnedIn= 1200;
				memoryPointsGetInGunner = "pos turret";
				memoryPointsGetInGunnerDir = "pos turret dir";
				discreteDistance[] = {100, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500};
				discreteDistanceInitIndex = 1;
				gunnerOpticsModel = "\A3\weapons_f\reticle\optics_empty";
				startEngine=0;
				stabilizedInAxes=0;
				class ViewOptics {
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
				class ViewGunner: ViewOptics {};
			};
			class SideTurret: MainTurret
			{
				gunnerName = "Gunner (M240)";
				weapons[]={"vurtual_m240_veh"};
				memoryPointGun="OtocHlaven_2";
				magazines[]={"vurtual_100rnd_762x51_box","vurtual_100rnd_762x51_box","vurtual_100rnd_762x51_box","vurtual_100rnd_762x51_box","vurtual_100rnd_762x51_box","vurtual_100rnd_762x51_box","vurtual_100rnd_762x51_box","vurtual_100rnd_762x51_box","vurtual_100rnd_762x51_box","vurtual_100rnd_762x51_box","vurtual_100rnd_762x51_box"};
				soundServo[]={\ca\wheeled\Data\Sound\servo3, db-80, 1.1};
				gunnerInAction = "passenger_low01";
				gunnerRightHandAnimName = "";
				gunnerLeftHandAnimName = "";
				selectionFireAnim = "muzzleflash2";
				gunnerAction = "passenger_inside_2";
				personTurretAction = "passenger_inside_2";
				animationSourceHatch = "";
				commanding = 1;
				primaryGunner = 0;
				minOutElev=-45;
				minOutTurn=-105;
				maxOutTurn=-30;
				primaryObserver = 1;
				discreteDistance[] = {200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800};
				discreteDistanceInitIndex = 1;
				proxyType = "CPCargo";
				proxyIndex = 1;
				minElev = -18; maxElev = +20;
				minTurn=-65; maxTurn=35;
				gunBeg = "usti hlavne_2";
				gunEnd = "konec hlavne_2";
				body = "SideTurret";
				gun = "SideGun";
				memoryPointGunnerOptics= "gunnerview_2";
				animationSourceBody = "SideTurret";
				animationSourceGun = "SideGun";
				memoryPointsGetInGunner = "pos codriver";
				memoryPointsGetInGunnerDir = "pos codriver dir";
				LODOpticsIn = 1200;
				LODTurnedOut = 1200;
				LODTurnedIn= 1200;
				outGunnerMayFire=1;
				inGunnerMayFire=1;
				startEngine=0;
				class ViewOptics: ViewOptics {};
				class ViewGunner: ViewOptics {};
			};
			class CargoTurret_Passenger_L: CargoTurret_Passenger_L {
				gunnerName = "Left passenger";
				gunnerDoor = "door_left2";
				proxyIndex = 2;
				maxTurn = 105;
				minTurn = 30;
				memoryPointsGetInGunner = "pos leftseat";
				memoryPointsGetInGunnerDir = "pos leftseat dir";
				enabledByAnimationSource = "";
				commanding=0;
			};
			class CargoTurret_Passenger_R: CargoTurret_Passenger_R {
				gunnerName = "Right passenger";
				gunnerDoor = "door_right2";
				proxyIndex = 3;
				memoryPointsGetInGunner = "pos rightseat";
				memoryPointsGetInGunnerDir = "pos rightseat dir";
				enabledByAnimationSource = "";
				commanding=0;
			};
			class CargoTurret_Tailgate_L_B: CargoTurret_Tailgate_L {
				gunnerName = "Passenger (Bedside Left)";
				proxyIndex = 4;
				memoryPointsGetInGunner = "pos leftside";
				memoryPointsGetInGunnerDir = "pos leftside dir";
				gunnerCompartments = "Compartment1";
				commanding = 0;
				maxElev = 75;
				minElev = -10;
				maxTurn = 95;
				minTurn = -15;
			};
			class CargoTurret_Tailgate_R_B: CargoTurret_Tailgate_R {
				gunnerName = "Passenger (Bedside right)";
				proxyIndex = 5;
				memoryPointsGetInGunner = "pos rightside";
				memoryPointsGetInGunnerDir = "pos rightside dir";
				gunnerCompartments = "Compartment1";
				commanding = 0;
				maxElev = 75;
				minElev = -10;
				maxTurn = 15;
				minTurn = -95;
			};
			class CargoTurret_Tailgate_L: CargoTurret_Tailgate_L {
				proxyIndex = 6;
				commanding=0;
				gunnerCompartments = "Compartment1";
			};
			class CargoTurret_Tailgate_R: CargoTurret_Tailgate_R {
				proxyIndex = 7;
				commanding=0;
				gunnerCompartments = "Compartment1";
			};
		};
	};
	class vurtual_gmv_m2: vurtual_gmv {
		scope = 2;
		displayName = "HMMWV M1113 GMV (M2)";
		model = "\vurtual_m998_gmv\vurtual_gmv_m2.p3d";
		class AnimationSources:AnimationSources {
			class ReloadAnim{source="reload";weapon="vurtual_M2";};
			class ReloadMagazine{source="reloadmagazine";weapon="vurtual_M2";};
			class Revolving{source="revolving";weapon="vurtual_M2";};
			class betseat_fold: bedseat_fold {};
		};
		class Turrets: Turrets {
			class MainTurret: MainTurret {
				weapons[]={"vurtual_M2"};
				magazines[] = {"100Rnd_127x99_mag_Tracer_Yellow","100Rnd_127x99_mag_Tracer_Yellow","100Rnd_127x99_mag_Tracer_Yellow","100Rnd_127x99_mag_Tracer_Yellow","100Rnd_127x99_mag_Tracer_Yellow","100Rnd_127x99_mag_Tracer_Yellow","100Rnd_127x99_mag_Tracer_Yellow","100Rnd_127x99_mag_Tracer_Yellow"};
				gunnerName = "Gunner (M2)";
				discreteDistance[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1200, 1500};
				discreteDistanceInitIndex = 2;
			};
			class SideTurret: SideTurret {};
			class CargoTurret_Passenger_L: CargoTurret_Passenger_L {};
			class CargoTurret_Passenger_R: CargoTurret_Passenger_R {};
			class CargoTurret_Tailgate_L: CargoTurret_Tailgate_L {};
			class CargoTurret_Tailgate_R: CargoTurret_Tailgate_R {};
			class CargoTurret_Tailgate_L_B: CargoTurret_Tailgate_L_B {};
			class CargoTurret_Tailgate_R_B: CargoTurret_Tailgate_R_B {};
		};
	};
};
class CfgWeapons {
	class MGun;
	class vurtual_m240_veh: MGun {
		bullet1[] = {"A3\Sounds_F\weapons\bullets\7_62-dirt1",1,1,15};
		bullet2[] = {"A3\Sounds_F\weapons\bullets\7_62-dirt2",1,1,15};
		bullet3[] = {"A3\Sounds_F\weapons\bullets\7_62-dirt3",1,1,15};
		bullet4[] = {"A3\Sounds_F\weapons\bullets\7_62-dirt4",1,1,15};
		bullet5[] = {"A3\Sounds_F\weapons\bullets\7_62-hard1",1,1,15};
		bullet6[] = {"A3\Sounds_F\weapons\bullets\7_62-hard2",1,1,15};
		bullet7[] = {"A3\Sounds_F\weapons\bullets\7_62-hard3",1,1,15};
		bullet8[] = {"A3\Sounds_F\weapons\bullets\7_62-hard4",1,1,15};
		bullet9[] = {"A3\Sounds_F\weapons\bullets\7_62-metal1",1,1,15};
		bullet10[] = {"A3\Sounds_F\weapons\bullets\7_62-metal2",1,1,15};
		bullet11[] = {"A3\Sounds_F\weapons\bullets\7_62-metal3",1,1,15};
		bullet12[] = {"A3\Sounds_F\weapons\bullets\7_62-metal4",1,1,15};
		class GunParticles {
			class effect1 {
				positionName = "nabojnicestart2";
				directionName = "nabojniceend2";
				effectName="MachineGunEject2";
			};
			class effect2 {
				positionName = "usti hlavne_2";
				directionName = "konec hlavne_2";
				effectName = "RifleAssaultCloud";
			};
			class effect3 {
				positionName = "nabojnicestart2";
				directionName = "nabojniceend2";
				effectName="vurtual_762_cartridge";
			};
		};
			
		soundBullet[]={bullet1, 0.083, bullet2, 0.083, bullet3, 0.083, bullet4, 0.083, bullet5, 0.083, bullet6, 0.083, bullet7, 0.083, bullet8, 0.083, bullet9, 0.083, bullet10, 0.083, bullet11, 0.083, bullet12, 0.083};

		scope = 1;
		displayName = "M240";
		soundContinuous = false;
		aiDispersionCoefY=21; // 7
		aiDispersionCoefX=21;
		magazines[] = {"vurtual_100Rnd_762x51_box"};
		magazineReloadTime=5;
		sound[] = {"",1,1};
		canLock = 0;
		modes[] = {"manual","close", "short", "medium", "far"};
		maxRange=1800;
		autoReload=1;
		sounds[]={"StandardSound"};
		ballisticsComputer = 2;
		class manual: MGun
		{
			class StandardSound {
				begin1[] = {"A3\Sounds_F\arsenal\weapons\Machineguns\Zafir\Zafir_short_01",1.77828,1,1200};
				begin2[] = {"A3\Sounds_F\arsenal\weapons\Machineguns\Zafir\Zafir_short_02",1.77828,1,1200};
				begin3[] = {"A3\Sounds_F\arsenal\weapons\Machineguns\Zafir\Zafir_short_03",1.77828,1,1200};
				closure1[] = {"A3\Sounds_F\arsenal\weapons\Machineguns\Zafir\Closure_zafir_01",0.562341,1,10};
				closure2[] = {"A3\Sounds_F\arsenal\weapons\Machineguns\Zafir\Closure_zafir_02",0.562341,1,10};
				soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.34};
				soundClosure[] = {"closure1",0.5,"closure2",0.5};
				soundSetShot[] = {"Zafir_Shot_SoundSet","Zafir_Tail_SoundSet","Zafir_InteriorTail_SoundSet"};
			};
			displayName = "M240";
			autoFire = 1;
			reloadTime = 0.075;
	        dispersion=0.0012;
			showToPlayer = true;
                        burst = 1;
			aiRateOfFire = 1;
			aiRateOfFireDistance = 50;
			minRange=0;minRangeProbab=0.01;
			midRange=1;midRangeProbab=0.01;
			maxRange=2;maxRangeProbab=0.01;
			maxZeroing=1800;
		}
		class close: manual
		{
                        showToPlayer = false;
                        soundBurst = false;
                        burst = 10; //Rg 6;
			aiRateOfFire = 0.5;
			aiRateOfFireDistance = 50;
			minRange=0;minRangeProbab=0.05;
			midRange=100;midRangeProbab=0.58;
			maxRange=200;maxRangeProbab=0.04;
		};
		class short: close
		{
			burst = 8; //Rg 6;
			aiRateOfFire = 2;
			aiRateOfFireDistance = 300; //Rg 200;
			minRange=50;minRangeProbab=0.05;
			midRange=200;midRangeProbab=0.58; //Rg 100;
			maxRange=400;maxRangeProbab=0.04; //Rg 200;
		};
		class medium: close
		{
			burst = 4; //Rg 8;
			aiRateOfFire = 3; //Rg 4;
			aiRateOfFireDistance = 600; //Rg 400;
			minRange=300;minRangeProbab=0.05;
			midRange=400;midRangeProbab=0.58; //Rg 300;
			maxRange=600;maxRangeProbab=0.04; //Rg 400;
		};
		class far: close
		{
			burst = 5; //Rg 7;
			aiRateOfFire = 5; //Rg 7;
			aiRateOfFireDistance = 1000; //Rg 600;
			minRange=500;minRangeProbab=0.05;
			midRange=600;midRangeProbab=0.4; //Rg 500;
			maxRange=800;maxRangeProbab=0.01; //Rg 600;
		};
	};
	class HMG_M2;
	class vurtual_M2: HMG_M2 {
		displayName = "M2";
		scope = 1;
		class GunParticles {
			class effect1 {
				positionName = "nabojnicestart1";
				directionName = "nabojniceend1";
				effectName="MachineGunEject";
			};
			class effect2 {
				positionName = "usti hlavne";
				directionName = "konec hlavne";
				effectName = "MachineGunCloud";
			};
			class effect3 {
				positionName = "nabojnicestart1";
				directionName = "nabojniceend1";
				effectName="MachineGunCartridge2";
			};
		};
	};
	class vurtual_MK19: MGun {
		bullet1[] = {"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Metal_01",0.281838,1,10};
		bullet10[] = {"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Grass_02",0.281838,1,10};
		bullet11[] = {"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Grass_03",0.281838,1,10};
		bullet12[] = {"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Grass_04",0.281838,1,10};
		bullet2[] = {"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Metal_02",0.281838,1,10};
		bullet3[] = {"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Metal_03",0.281838,1,10};
		bullet4[] = {"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Metal_04",0.281838,1,10};
		bullet5[] = {"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Dirt_01",0.281838,1,10};
		bullet6[] = {"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Dirt_02",0.281838,1,10};
		bullet7[] = {"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Dirt_03",0.281838,1,10};
		bullet8[] = {"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Dirt_04",0.281838,1,10};
		bullet9[] = {"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Grass_01",0.281838,1,10};
		soundBullet[] = {"bullet1",0.08,"bullet2",0.084,"bullet3",0.084,"bullet4",0.084,"bullet5",0.093,"bullet6",0.093,"bullet7",0.074,"bullet8",0.074,"bullet9",0.084,"bullet10",0.085,"bullet11",0.083,"bullet12",0.083};
		class GunParticles {
			class effect2 {
				positionName = "usti hlavne";
				directionName = "konec hlavne";
				effectName = "GrenadeLauncherCloud";
			};
			class effect3 {
				positionName = "nabojnicestart1";
				directionName = "nabojniceend1";
				effectName="vurtual_40mm_cartridge";
			};
		};
		autoReload=1;
		scope = 1;
		displayName = "Mk19";
		sound[] = {"",1,1};
		modes[] = {"manual","close","short","medium","far"};
		maxRange=1500;
		ballisticsComputer = 2;
		class manual: MGun
		{
		class StandardSound {
			begin1[] = {"A3\Sounds_F\arsenal\weapons_static\Static_GMG\GMG_01",1.12202,1,1200};
			begin2[] = {"A3\Sounds_F\arsenal\weapons_static\Static_GMG\GMG_02",1.12202,1,1200};
			begin3[] = {"A3\Sounds_F\arsenal\weapons_static\Static_GMG\GMG_03",1.12202,1,1200};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.34};
			soundSetShot[] = {"GMG40mm_Shot_SoundSet","GMG40mm_Tail_SoundSet"};
		};
			maxZeroing=1500;
			displayName = "Mk19";
			autoFire = 1;
			reloadTime = 0.17;
	               dispersion = 0.006;

			showToPlayer = true;
                        burst = 1;
			aiRateOfFire = 0.17;
			aiRateOfFireDistance = 50;
			minRange=0;minRangeProbab=0.01;
			midRange=1;midRangeProbab=0.01;
			maxRange=2;maxRangeProbab=0.01;
		}
		class close: manual
		{
                        showToPlayer = false;
                        soundBurst = false;
                        burst = 1
			aiRateOfFire = 1;
			aiRateOfFireDistance = 50;
			minRange=0;minRangeProbab=0.05;
			midRange=20;midRangeProbab=0.7;
			maxRange=50;maxRangeProbab=0.1;
		};
		class short: close
		{
			burst = 5;
			aiRateOfFire = 2;
			aiRateOfFireDistance = 300;
			minRange=50;minRangeProbab=0.05;
			midRange=150;midRangeProbab=0.7
			maxRange=300;maxRangeProbab=0.1;
		};
		class medium: close
		{
			burst = 4;
			aiRateOfFire = 4;
			aiRateOfFireDistance = 600;
			minRange=200;minRangeProbab=0.05;
			midRange=400;midRangeProbab=0.7;
			maxRange=600;maxRangeProbab=0.1;
		};
		class far: close
		{
			burst = 3;
			aiRateOfFire = 5; //Rg 7;
			aiRateOfFireDistance = 1000; //Rg 600;
			minRange=400;minRangeProbab=0.05;
			midRange=750;midRangeProbab=0.4; //Rg 500;
			maxRange=1000;maxRangeProbab=0.01; //Rg 600;
		};
		sounds[]={"StandardSound"};
		magazines[] = {"32Rnd_40mm_G_belt"};
		magazineReloadTime = 10;
		canLock = 0;
	};
};
class cfgMagazines {
	class VehicleMagazine;
	class vurtual_100Rnd_762x51_box: VehicleMagazine {
		author = "vurtual";
		scope = 1;
		count = 100;
		displayname = "7.62x51mm 100Rnd belt";
		ammo = "B_762x51_Tracer_Yellow";
		tracersEvery = 5;
		lastRoundsTracer = 4;
		nameSound = "mgun";
		mass = 40;
	};
};
class cfgCloudlets {
	class MachineGunCartridge2;
	class vurtual_762_cartridge: MachineGunCartridge2 {
		//moveVelocity[] = { "-directionX * 5", "- directionY * 2", "- directionZ * 2" };
		size[] = {1};
		sizeVar = 0;
	};
	class vurtual_40mm_cartridge: MachineGunCartridge2 {
		size[] = {1};
		sizeVar = 0;
		particleShape = "vurtual_m998_gmv\vurtual_eject_40mm.p3d";
	};
};
class vurtual_762_cartridge {
	class vurtual_762_cartridge {
		simulation = "particles";
		type = "vurtual_762_cartridge";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.05;
		qualityLevel = 2;
	};
	class vurtual_762_cartridgeMed: vurtual_762_cartridge {
		qualityLevel = 1;
	};
};
class vurtual_40mm_cartridge {
	class vurtual_40mm_cartridge {
		simulation = "particles";
		type = "vurtual_40mm_cartridge";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.05;
		qualityLevel = 2;
	};
	class vurtual_40mm_cartridgeMed: vurtual_40mm_cartridge {
		qualityLevel = 1;
	};
};