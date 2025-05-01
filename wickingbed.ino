const int REED_PIN_UP = 2;	// Pin connected to reed switch
const int REED_PIN_DOWN = 3;	// Pin connected to reed switch

bool reservoir_full = false;

void setup() {
	Serial.begin(9600);
	pinMode(REED_PIN_UP, INPUT_PULLUP);	// Enable internal pull-up for the reed switch
  pinMode(REED_PIN_DOWN, INPUT_PULLUP);
}

void loop() {
	int full = digitalRead(REED_PIN_UP);
  int empty = digitalRead(REED_PIN_DOWN);
	
	// If the pin reads low, the switch is closed.
	if (full == LOW) {
    if (reservoir_full == false) {
      reservoir_full = true;
		  Serial.println("Reservoir full");
    }
	}
	else if (empty == LOW) {
    if (reservoir_full == true) {
      reservoir_full = false;
      Serial.println("Reservoir empty");
    }
  }

  delay(100);
}