
int cds_pin = 0;    // cds pin A0

void setup() {
  Serial.begin(115200);  
} 

void loop() { 
  int val = analogRead(cds_pin);    //cds value read

  Serial.printf("cds value: %d", val);

  delay(500);
}