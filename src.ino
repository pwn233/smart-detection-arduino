// IOT + Cloud Project
int LED_PIN = 13;
const unsigned int TRIG_PIN = 8;
const unsigned int ECHO_PIN = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration, distance;
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = microsecondsToCentimeters(duration);
  if(distance < 16) {
    if(digitalRead(LED_PIN) == LOW) {
      digitalWrite(LED_PIN, HIGH);
      Serial.println(distance);
    }
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  
  delay(1000);
}
long microsecondsToCentimeters(long microseconds) {
  return microseconds/29/2;
}
