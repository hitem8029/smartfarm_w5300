#include "Arduino.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN PA5        //D13
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

//for monitoring
const int soil_pin = PA3; // A0
const int cds_pin = PC0;  // A1
const int trig_pin = PC7; // D8
const int echo_pin = PF9; // D7

//for motor_relay
const int motor_relay = PA6; //D12

#define SOUND_SPEED 340
#define TRIG_PULSE_DURATION_US 10

long ultrason_duration;
float distance_cm;

void setup() {
  Serial3.setTx(PC10);
  Serial3.setRx(PC11);
  Serial3.begin(115200);
  pinMode(trig_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
  
  dht.begin();
  delay(1000);
}

void loop() {

  int soil_val;
  int cds_val;
  
  soil_val = analogRead(soil_pin);
  cds_val = analogRead(cds_pin);
  
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
    // Créer une impulsion de 10 µs
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(TRIG_PULSE_DURATION_US);
  digitalWrite(trig_pin, LOW);  
  
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();
  float F = dht.readTemperature(true);

  //Check if any reads failed and exit early (to try again)
  if(isnan(hum) || isnan(temp) || isnan(F)){
    Serial3.println("Failed to read from DHT sensor!");
    return;
  }
  ultrason_duration = pulseIn(echo_pin, HIGH);

  distance_cm = ultrason_duration * SOUND_SPEED/2 * 0.0001;

  Serial3.print("Distance (cm): ");
  Serial3.println(distance_cm);
  Serial3.printf("Soil pin: %d\r\n", soil_val);  
  Serial3.print("Humidity: ");
  Serial3.print(hum);
  Serial3.print(" % ");
  Serial3.print("Temperature: ");
  Serial3.print(temp);
  Serial3.println("C");

  Serial3.printf("cds value: %d\r\n", cds_val);

  delay(250);
}
