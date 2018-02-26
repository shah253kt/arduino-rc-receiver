#include <RcChannel.h>

RcChannel ch(4);

void setup() {
	Serial.begin(9600);
}

void loop() {
	Serial.println(ch.readRaw());
}
