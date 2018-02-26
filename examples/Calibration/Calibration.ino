#include <RcChannel.h>

RcChannel ch(4);

void setup() {
	Serial.begin(9600);

	//This form is more suitable if you have multiple channels to calibrate.
	while (millis() < 3000) {
		ch.calibrate();
	}
	//OR
	//ch.calibrate(3000);
}

void loop() {
	Serial.println(ch.readPercentage());
}
