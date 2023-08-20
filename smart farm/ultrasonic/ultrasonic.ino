const int trig_pin = PC7; // D9
const int echo_pin = PF9; // D8

// Vitesse du son dans l'air
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
}

void loop() {
  
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
    // Créer une impulsion de 10 µs
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(TRIG_PULSE_DURATION_US);
  digitalWrite(trig_pin, LOW);  

  ultrason_duration = pulseIn(echo_pin, HIGH);

  distance_cm = ultrason_duration * SOUND_SPEED/2 * 0.0001;

  Serial3.print("Distance (cm): ");
  Serial3.println(distance_cm);

  delay(250);

}
