void setup() {
  // put your setup code here, to run once:
	Serial.begin(9600);
	String cmd[]="";
	pinMode(13, OUTPUT);
}

void loop() {
	// Try to convert this to a sequential command analysis. E.g. PIN 15 HIGH
	if (Serial.available() > 0) {
		String cmd = Serial.readString();
		Serial.println(cmd);

	if (cmd == "LON") {
		digitalWrite (13, HIGH);
		Serial.println ("Switching ON");
	}
	else if (cmd == "LOFF") {
		digitalWrite (13, LOW);
		Serial.println ("Switching OFF");
	}
		
	}
	
	}

