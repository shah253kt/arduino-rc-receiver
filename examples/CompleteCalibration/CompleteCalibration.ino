#include <RcChannel.h>

RcChannel rc[] = {11, 10, 9, 8};

void setup() {
  Serial.begin(9600);

  Serial.println("Move all channels in all directions");

  for(byte i=0; i<4; i++) {
    rc[i].setMinVal(2000);
    rc[i].setMaxVal(0);
  }

  while(millis() < 5000) {
    for(byte i=0; i<4; i++) {
      rc[i].calibrate();
    }
  }
  
  for(byte i=0; i<4; i++) {
    Serial.print(i + 1);
    Serial.print(":\t");
    Serial.print(rc[i].getMinVal());
    Serial.print("\t");
    Serial.print(rc[i].getMidVal());
    Serial.print("\t");
    Serial.println(rc[i].getMaxVal());
  }
  
  Serial.println("Use the values above when initializing your RC channels.");
}

void loop() {
  
}
