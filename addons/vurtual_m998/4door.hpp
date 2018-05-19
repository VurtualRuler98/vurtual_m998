class Turrets: Turrets {
	class CargoTurret_CoDriver: CargoTurret_CoDriver {};
	class CargoTurret_Passenger_L: CargoTurret_CoDriver {
		gunnerName = "Left passenger";
		gunnerDoor = "door_left2";
		proxyIndex = 2;
		maxTurn = 105;
		minTurn = 30;
		memoryPointsGetInGunner = "pos leftseat";
		memoryPointsGetInGunnerDir = "pos leftseat dir";
		enabledByAnimationSource = "window_left";
	};
	class CargoTurret_Passenger_R: CargoTurret_CoDriver {
		gunnerName = "Right passenger";
		gunnerDoor = "door_right2";
		proxyIndex = 3;
		memoryPointsGetInGunner = "pos rightseat";
		memoryPointsGetInGunnerDir = "pos rightseat dir";
		enabledByAnimationSource = "window_right";
	};
	class CargoTurret_Tailgate_L_B: CargoTurret_Tailgate_L {
		gunnerName = "Passenger (Bedside Left)";
		proxyIndex = 4;
		memoryPointsGetInGunner = "pos leftside";
		memoryPointsGetInGunnerDir = "pos leftside dir";
		gunnerCompartments = "Compartment2";
		commanding = 0;
		maxElev = 75;
		minElev = -10;
		maxTurn = 95;
		minTurn = -15;
	};
	class CargoTurret_Tailgate_R_B: CargoTurret_Tailgate_R {
		gunnerName = "Passenger (Bedside Right)";
		proxyIndex = 5;
		memoryPointsGetInGunner = "pos rightside";
		memoryPointsGetInGunnerDir = "pos rightside dir";
		gunnerCompartments = "Compartment2";
		commanding = 0;
		maxElev = 75;
		minElev = -10;
		maxTurn = 15;
		minTurn = -95;
	};
	class CargoTurret_Tailgate_L: CargoTurret_Tailgate_L {
		proxyIndex = 6;
	};
	class CargoTurret_Tailgate_R: CargoTurret_Tailgate_R {
		proxyIndex = 7;
	};
};
transportSoldier = 0;
VIVPassengers[] = {3,4,5,6};//0, 1, 2 are front passenger, 3 and 4 are cargoTurret
class AnimationSources: AnimationSources {
	class bedseat_fold: bedseat_fold {
		lockCargo[] = {3,4,5,6};
	};
	class Seats_A2 {
		source = "user";
		initPhase = 0;
		animPeriod = 0.1;
		displayName = "Install A2 seats";
		onPhaseChanged = "(_this select 0) animateSource ['Seats_A2',(_this select 1),true]";
		forceAnimatePhase = 1;
		forceAnimate[] = {"Seats_A1",1};
	};
	class door_hide: door_hide {};
	class Door_Left2 {
		source = "door";
		initPhase = 0;
		animPeriod = 0.4;
	};
	class Door_Right2 {
		source = "door";
		initPhase = 0;
		animPeriod = 0.4;
	};
	class window_left {
		source = "door";
		initPhase = 0;
		animPeriod = 0.5;
	};
	class window_right {
		source = "door";
		initPhase = 0;
		animPeriod = 0.5;
	};
	//class door_left2_window: door_left_window {};
	//class door_right2_window: door_left_window {};
};
cargoCompartments[] = {"Compartment2"};
cargoIsCoDriver[] = {0};
cargoProxyIndexes[] = {4,5};
soundAttenuationCargo[] = {0};
cargoDoors[] = {"tailgate_fold"};
vurtual_hmmwv_4door = 1;