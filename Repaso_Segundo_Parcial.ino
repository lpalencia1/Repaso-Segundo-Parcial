int sensorPin = 5;

int LedRojo = 2;
int LedAmarillo = 3;
int LedAzul = 4;
int LedVerde = 5;
int LedBlanco = 6;
const int Trigger = 11;
const int Echo = 12;

int op;

void setup() {
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger, LOW);

  pinMode(LedRojo, OUTPUT);
  pinMode(LedAmarillo, OUTPUT);
  pinMode(LedAzul, OUTPUT);
  pinMode(LedVerde, OUTPUT);
  pinMode(LedBlanco, OUTPUT);
}

void loop() {
  Leds();
  Sensor();
}

void Sensor() {
  long t;
  long d;

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);

  t = pulseIn(Echo, HIGH);
  d = t / 59;

  Serial.print("Distancia: ");
  Serial.print(d);
  Serial.print("cm");
  Serial.println();
  delay(100);
}

void Leds() {
  int sensorValue;
  sensorValue = analogRead(sensorPin);
  digitalWrite(LedRojo, HIGH);
  digitalWrite(LedAmarillo, HIGH);
  digitalWrite(LedAzul, HIGH);
  digitalWrite(LedVerde, HIGH);
  digitalWrite(LedRojo, HIGH);
  digitalWrite(LedBlanco, HIGH);
  delay(sensorValue);
  digitalWrite(LedRojo, LOW);
  digitalWrite(LedAmarillo, LOW);
  digitalWrite(LedAzul, LOW);
  digitalWrite(LedVerde, LOW);
  digitalWrite(LedRojo, LOW);
  digitalWrite(LedBlanco, LOW);
  delay(sensorValue);
}