#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN PA5 //D13
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial3.setTx(PC10);
  Serial3.setRx(PC11);
  Serial3.begin(115200);
  dht.begin();
}

void loop() {
  delay(1000);

  float hum = dht.readHumidity();
  float temp = dht.readTemperature();
  float F = dht.readTemperature(true);

  //Check if any reads failed and exit early (to try again)
  if(isnan(hum) || isnan(temp) || isnan(F)){
    Serial3.println("Failed to read from DHT sensor!");
    return;
  }

  Serial3.print("Humidity: ");
  Serial3.print(hum);
  Serial3.print(" % ");
  Serial3.print("Temperature: ");
  Serial3.print(temp);
  Serial3.println("C");  
}
