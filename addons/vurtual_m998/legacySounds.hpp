class Sounds {
	class Idle_ext {
		sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_ext_idle", 0.398107, 1, 150};
		frequency = "0.95	+	((rpm/	3600) factor[(800/	4500),(1400/	4500)])*0.15";
		volume = "engineOn*camPos*(((rpm/	3600) factor[(600/	4500),(1100/	4500)])	*	((rpm/	3600) factor[(1800/	4500),(1300/	4500)]))";
	};
	class Engine {
		sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_ext_low1", 0.446684, 1, 250};
		frequency = "0.9	+	((rpm/	3600) factor[(1400/	4500),(2100/	4500)])*0.2";
		volume = "engineOn*camPos*(((rpm/	3600) factor[(1400/	4500),(1800/	4500)])	*	((rpm/	3600) factor[(2300/	4500),(2000/	4500)]))";
	};
	class Engine1_ext {
		sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_ext_low2", 0.562341, 1, 300};
		frequency = "0.9	+		((rpm/	3600) factor[(2100/	4500),(2800/	4500)])*0.2";
		volume = "engineOn*camPos*(((rpm/	3600) factor[(1900/	4500),(2300/	4500)])	*	((rpm/	3600) factor[(3000/	4500),(2500/	4500)]))";
	};
	class Engine2_ext {
		sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_ext_mid", 0.707946, 1, 350};
		frequency = "0.9	+	((rpm/	3600) factor[(2800/	4500),(3600/	4500)])*0.2";
		volume = "engineOn*camPos*(((rpm/	3600) factor[(2500/	4500),(3100/	4500)])	*	((rpm/	3600) factor[(4500/	4500),(3700/	4500)]))";
	};
	class Engine3_ext {
		sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_ext_high", 1, 1, 400};
		frequency = "0.95	+	((rpm/	3600) factor[(3600/	4500),(4500/	4500)])*0.1";
		volume = "engineOn*camPos*((rpm/	3600) factor[(3800/	4500),(4500/	4500)])";
	};
	class IdleThrust {
		sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_ext_exhaust_idle", 0.562341, 1, 200};
		frequency = "0.95	+	((rpm/	3600) factor[(800/	4500),(1400/	4500)])*0.15";
		volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3600) factor[(600/	4500),(1100/	4500)])	*	((rpm/	3600) factor[(1800/	4500),(1300/	4500)]))";
	};
	class EngineThrust {
		sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_ext_exhaust_low1", 0.707946, 1, 350};
		frequency = "0.9	+	((rpm/	3600) factor[(1400/	4500),(2100/	4500)])*0.2";
		volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3600) factor[(1400/	4500),(1800/	4500)])	*	((rpm/	3600) factor[(2300/	4500),(2000/	4500)]))";
	};
	class Engine1_Thrust_ext {
		sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_ext_exhaust_low2", 0.891251, 1, 400};
		frequency = "0.9	+		((rpm/	3600) factor[(2100/	4500),(2800/	4500)])*0.2";
		volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3600) factor[(1900/	4500),(2300/	4500)])	*	((rpm/	3600) factor[(3000/	4500),(2500/	4500)]))";
	};
	class Engine2_Thrust_ext {
		sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_ext_exhaust_mid", 1.12202, 1, 425};
		frequency = "0.9	+	((rpm/	3600) factor[(2800/	4500),(3600/	4500)])*0.2";
		volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3600) factor[(2500/	4500),(3100/	4500)])	*	((rpm/	3600) factor[(4500/	4500),(3700/	4500)]))";
	};
	class Engine3_Thrust_ext {
		sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_ext_exhaust_high", 1.25893, 1, 450};
		frequency = "0.95	+	((rpm/	3600) factor[(3600/	4500),(4500/	4500)])*0.1";
		volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/	3600) factor[(3800/	4500),(4500/	4500)])";
	};
	class Idle_int {
		sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_int_idle", 0.251189, 1};
		frequency = "0.95	+	((rpm/	3600) factor[(800/	4500),(1400/	4500)])*0.15";
		volume = "engineOn*(1-camPos)*(((rpm/	3600) factor[(600/	4500),(1100/	4500)])	*	((rpm/	3600) factor[(1800/	4500),(1300/	4500)]))";
	};
	class Engine_int {
		sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_int_low1", 0.316228, 1};
		frequency = "0.9	+	((rpm/	3600) factor[(1400/	4500),(2100/	4500)])*0.2";
		volume = "engineOn*(1-camPos)*(((rpm/	3600) factor[(1400/	4500),(1800/	4500)])	*	((rpm/	3600) factor[(2300/	4500),(2000/	4500)]))";
	};
	class Engine1_int {
		sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_int_low2", 0.398107, 1};
		frequency = "0.9	+		((rpm/	3600) factor[(2100/	4500),(2800/	4500)])*0.2";
		volume = "engineOn*(1-camPos)*(((rpm/	3600) factor[(1900/	4500),(2300/	4500)])	*	((rpm/	3600) factor[(3000/	4500),(2500/	4500)]))";
	};
	class Engine2_int {
		sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_int_mid", 0.501187, 1};
		frequency = "0.9	+	((rpm/	3600) factor[(2800/	4500),(3600/	4500)])*0.2";
		volume = "engineOn*(1-camPos)*(((rpm/	3600) factor[(2500/	4500),(3100/	4500)])	*	((rpm/	3600) factor[(4500/	4500),(3700/	4500)]))";
	};
	class Engine3_int {
		sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_int_high", 0.630957, 1};
		frequency = "0.95	+	((rpm/	3600) factor[(3600/	4500),(4500/	4500)])*0.1";
		volume = "engineOn*(1-camPos)*((rpm/	3600) factor[(3800/	4500),(4500/	4500)])";
	};
	class IdleThrust_int {
		sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_int_exhaust_idle", 0.354813, 1};
		frequency = "0.95	+	((rpm/	3600) factor[(800/	4500),(1400/	4500)])*0.15";
		volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3600) factor[(600/	4500),(1100/	4500)])	*	((rpm/	3600) factor[(1800/	4500),(1300/	4500)]))";
	};
	class EngineThrust_int {
		sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_int_exhaust_low1", 0.446684, 1};
		frequency = "0.9	+	((rpm/	3600) factor[(1400/	4500),(2100/	4500)])*0.2";
		volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3600) factor[(1400/	4500),(1800/	4500)])	*	((rpm/	3600) factor[(2300/	4500),(2000/	4500)]))";
	};
	class Engine1_Thrust_int {
		sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_int_exhaust_low2", 0.562341, 1};
		frequency = "0.9	+		((rpm/	3600) factor[(2100/	4500),(2800/	4500)])*0.2";
		volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3600) factor[(1900/	4500),(2300/	4500)])	*	((rpm/	3600) factor[(3000/	4500),(2500/	4500)]))";
	};
	class Engine2_Thrust_int {
		sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_int_exhaust_mid", 0.707946, 1};
		frequency = "0.9	+	((rpm/	3600) factor[(2800/	4500),(3600/	4500)])*0.2";
		volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3600) factor[(2500/	4500),(3100/	4500)])	*	((rpm/	3600) factor[(4500/	4500),(3700/	4500)]))";
	};
	class Engine3_Thrust_int {
		sound[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_int_exhaust_high", 0.794328, 1};
		frequency = "0.95	+	((rpm/	3600) factor[(3600/	4500),(4500/	4500)])*0.1";
		volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/	3600) factor[(3800/	4500),(4500/	4500)])";
	};
	class TiresRockOut {
		sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_1", 1.41254, 1, 60};
		frequency = "1";
		volume = "camPos*rock*(Speed factor[2, 20])";
	};
	class TiresSandOut {
		sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-sand1", 1.41254, 1, 60};
		frequency = "1";
		volume = "camPos*sand*(Speed factor[2, 20])";
	};
	class TiresGrassOut {
		sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_2", 1.25893, 1, 60};
		frequency = "1";
		volume = "camPos*grass*(Speed factor[2, 20])";
	};
	class TiresMudOut {
		sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-mud2", 1.12202, 1, 60};
		frequency = "1";
		volume = "camPos*mud*(Speed factor[2, 20])";
	};
	class TiresGravelOut {
		sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_gravel_1", 1.25893, 1, 60};
		frequency = "1";
		volume = "camPos*gravel*(Speed factor[2, 20])";
	};
	class TiresAsphaltOut {
		sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_asfalt_2", 1.12202, 1, 60};
		frequency = "1";
		volume = "camPos*asphalt*(Speed factor[2, 20])";
	};
	class NoiseOut {
		sound[] = {"A3\Sounds_F\vehicles\soft\noises\noise_ext_car_3", 1.12202, 1, 90};
		frequency = "1";
		volume = "camPos*(damper0 max 0.02)*(Speed factor[0, 8])";
	};
	class TiresRockIn {
		sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_1", 0.707946, 1};
		frequency = "1";
		volume = "(1-camPos)*rock*(Speed factor[2, 20])";
	};
	class TiresSandIn {
		sound[] = {"A3\Sounds_F\vehicles\soft\tires\int-tires-sand2", 0.707946, 1};
		frequency = "1";
		volume = "(1-camPos)*sand*(Speed factor[2, 20])";
	};
	class TiresGrassIn {
		sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_2", 0.707946, 1};
		frequency = "1";
		volume = "(1-camPos)*grass*(Speed factor[2, 20])";
	};
	class TiresMudIn {
		sound[] = {"A3\Sounds_F\vehicles\soft\tires\int-tires-mud2", 0.707946, 1};
		frequency = "1";
		volume = "(1-camPos)*mud*(Speed factor[2, 20])";
	};
	class TiresGravelIn {
		sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_gravel_1", 0.707946, 1};
		frequency = "1";
		volume = "(1-camPos)*gravel*(Speed factor[2, 20])";
	};
	class TiresAsphaltIn {
		sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_asfalt_2", 0.707946, 1};
		frequency = "1";
		volume = "(1-camPos)*asphalt*(Speed factor[2, 20])";
	};
	class NoiseIn {
		sound[] = {"A3\Sounds_F\vehicles\soft\noises\noise_int_car_3", 0.562341, 1};
		frequency = "1";
		volume = "(damper0 max 0.1)*(Speed factor[0, 8])*(1-camPos)";
	};
	class breaking_ext_road {
		sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04", 0.707946, 1, 80};
		frequency = 1;
		volume = "engineOn*camPos*asphalt*(LongSlipDrive factor[-0.15, -0.3])*(Speed factor[2, 10])";
	};
	class acceleration_ext_road {
		sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02", 0.707946, 1, 80};
		frequency = 1;
		volume = "engineOn*camPos*asphalt*(LongSlipDrive factor[0.15, 0.3])*(Speed factor[10, 0])";
	};
	class turn_left_ext_road {
		sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02", 0.707946, 1, 80};
		frequency = 1;
		volume = "engineOn*camPos*asphalt*(latSlipDrive factor[0.15, 0.3])*(Speed factor[0, 10])";
	};
	class turn_right_ext_road {
		sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02", 0.707946, 1, 80};
		frequency = 1;
		volume = "engineOn*camPos*asphalt*(latSlipDrive factor[-0.15, -0.3])*(Speed factor[0, 10])";
	};
	class breaking_ext_dirt {
		sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_14_dirt_breaking", 0.707946, 1, 60};
		frequency = 1;
		volume = "engineOn*camPos*(1-asphalt)*(LongSlipDrive factor[-0.15, -0.3])*(Speed factor[2, 10])";
	};
	class acceleration_ext_dirt {
		sound[] = {"A3\Sounds_F\vehicles\soft\noises\acceleration_dirt_ext_1", 0.707946, 1, 60};
		frequency = 1;
		volume = "engineOn*camPos*(1-asphalt)*(LongSlipDrive factor[0.15, 0.3])*(Speed factor[10, 0])";
	};
	class turn_left_ext_dirt {
		sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt", 0.707946, 1, 60};
		frequency = 1;
		volume = "engineOn*camPos*(1-asphalt)*(latSlipDrive factor[0.15, 0.3])*(Speed factor[0, 10])";
	};
	class turn_right_ext_dirt {
		sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt", 0.707946, 1, 60};
		frequency = 1;
		volume = "engineOn*camPos*(1-asphalt)*(latSlipDrive factor[-0.15, -0.3])*(Speed factor[0, 10])";
	};
	class breaking_int_road {
		sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04_int", 0.630957, 1};
		frequency = 1;
		volume = "engineOn*asphalt*(1-camPos)*(LongSlipDrive factor[-0.15, -0.3])*(Speed factor[2, 6])";
	};
	class acceleration_int_road {
		sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int", 0.630957, 1};
		frequency = 1;
		volume = "engineOn*asphalt*(1-camPos)*(LongSlipDrive factor[0.15, 0.3])*(Speed factor[10, 0])";
	};
	class turn_left_int_road {
		sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int", 0.630957, 1};
		frequency = 1;
		volume = "engineOn*asphalt*(1-camPos)*(latSlipDrive factor[0.15, 0.3])*(Speed factor[0, 10])";
	};
	class turn_right_int_road {
		sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int", 0.630957, 1};
		frequency = 1;
		volume = "engineOn*asphalt*(1-camPos)*(latSlipDrive factor[-0.15, -0.3])*(Speed factor[0, 10])";
	};
	class breaking_int_dirt {
		sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_14_dirt_breaking_int", 0.630957, 1};
		frequency = 1;
		volume = "engineOn*(1-asphalt)*(1-camPos)*(LongSlipDrive factor[-0.15, -0.3])*(Speed factor[2, 6])";
	};
	class acceleration_int_dirt {
		sound[] = {"A3\Sounds_F\vehicles\soft\noises\acceleration_dirt_int_1", 0.630957, 1};
		frequency = 1;
		volume = "engineOn*(1-asphalt)*(1-camPos)*(LongSlipDrive factor[0.15, 0.3])*(Speed factor[10, 0])";
	};
	class turn_left_int_dirt {
		sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt_int", 0.630957, 1};
		frequency = 1;
		volume = "engineOn*(1-asphalt)*(1-camPos)*(latSlipDrive factor[0.15, 0.3])*(Speed factor[0, 10])";
	};
	class turn_right_int_dirt {
		sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt_int", 0.630957, 1};
		frequency = 1;
		volume = "engineOn*(1-asphalt)*(1-camPos)*(latSlipDrive factor[-0.15, -0.3])*(Speed factor[0, 10])";
	};
	class Waternoise_ext {
		sound[] = {"A3\Sounds_F\vehicles\noises\soft_driving_in_water", 0.501187, 1, 300};
		frequency = "1";
		volume = "(Speed factor[0, 10]) * water * camPos + (Speed factor[-0.1, -10]) * water * camPos";
	};
	class Waternoise_int {
		sound[] = {"A3\Sounds_F\vehicles\noises\soft_driving_in_water_int", 0.354813, 1, 100};
		frequency = "1";
		volume = "(Speed factor[0, 10]) * water * (1-camPos)* 0.8 + (Speed factor[-0.1, -10]) * water * (1-camPos) *0.8";
	};
	class RainExt {
		sound[] = {"A3\Sounds_F\vehicles\noises\rain1_ext", 1, 1, 100};
		frequency = 1;
		volume = "camPos * (rain - rotorSpeed/2) * 2";
	};
	class RainInt {
		sound[] = {"A3\Sounds_F\vehicles\noises\rain1_int", 1, 1, 100};
		frequency = 1;
		volume = "(1-camPos)*(rain - rotorSpeed/2)*2";
	};
};

