	
	
	String cmd;
	char cmdMode[2];
	byte nextSpace, lastSpace, cmdPinNum;
	int cmdValue;

void setup() {
  // put your setup code here, to run once:
	Serial.begin(9600);
	pinMode(13, OUTPUT);
}

void loop() {
	if (Serial.available() > 0) {
		cmd = Serial.readString();
		extractCmd(cmd);
	}
}

void extractCmd (String cmd) {
	nextSpace = cmd.indexOf(' ');
	cmd.substring(0,nextSpace).toCharArray(cmdMode,cmd.substring(0,nextSpace).length()); //extracts the charachters before the first space and converts them to char array.
	lastSpace = nextSpace;
	nextSpace = cmd.indexOf(' ',lastSpace);
	cmdPinNum = cmd.substring(lastSpace+1,nextSpace).toInt();
	lastSpace = nextSpace;
	nextSpace = cmd.indexOf(' ',lastSpace);
	cmdValue = cmd.substring(lastSpace+1,nextSpace).toInt();
}