
#define VERBOSE

#ifdef VERBOSE
#endif	

String cmd;
char cmdMode[2];
byte nextSpace, lastSpace, cmdPinNum;
int cmdValue;

void setup() {
	
	Serial.begin(9600);
	
}

void loop() {
	
	if (Serial.available() > 0) {
		cmd = Serial.readString();
		delay (1);
		extractCmd(cmd);
		delay (1);
		cmd = "";
		
		if (strcmp(cmdMode,"DR") == 0) {
			#ifdef VERBOSE
			Serial.print("Digital Read from pin number ");
			Serial.print(cmdPinNum);
			Serial.print(" :");
			Serial.println(DigRead());
			#endif
		}
		if (strcmp(cmdMode,"DW") == 0) {
			Serial.print("Writing ");
			Serial.print((bool)cmdValue);
			Serial.print(" to pin number: ");
			Serial.println(cmdPinNum);
			DigWrite();
		
		}
	}
	
}

void extractCmd (String cmd) {
	nextSpace = cmd.indexOf(' ');
	cmd.substring(0,nextSpace).toCharArray(cmdMode,5); //extracts the charachters before the first space and converts them to char array.
	lastSpace = nextSpace;
	nextSpace = cmd.indexOf(' ',lastSpace+1);
	cmdPinNum = cmd.substring(lastSpace+1,nextSpace).toInt();
	lastSpace = nextSpace;
	nextSpace = cmd.indexOf(' ',lastSpace+1);
	cmdValue = cmd.substring(lastSpace+1,nextSpace).toInt();
	
	
	// Debug
	Serial.print("cmd: ");
	Serial.println(cmd);
	Serial.print("cmdMode: ");
	Serial.println(cmdMode);
	Serial.print("cmdPinNum: ");
	Serial.println(cmdPinNum);
	Serial.print("cmdValue: ");
	Serial.println(cmdValue);
	
	
}

bool DigRead() {
	pinMode(cmdPinNum,INPUT);
	return digitalRead(cmdPinNum);
}

void DigWrite() {
	pinMode(cmdPinNum,OUTPUT);
	digitalWrite(cmdPinNum, (bool)cmdValue);
}