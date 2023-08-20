#include "Arduino.h"

const int soil_pin = PA3;

void setup() {
  Serial3.setTx(PC10);
  Serial3.setRx(PC11);
  Serial3.begin(115200);
}

void loop() {  
//  Serial3.printf("TEST");
  int soil_val;
  soil_val = analogRead(soil_pin);
  Serial3.printf("Soil pin: %d\r\n", soil_val);  
  delay(1000);

}
