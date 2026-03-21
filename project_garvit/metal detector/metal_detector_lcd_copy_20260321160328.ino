int coilPin = 8;
int buzzer = 9;

unsigned long duration;
int threshold = 500;

void setup() {
  pinMode(coilPin, OUTPUT);
  pinMode(buzzer, OUTPUT);-
  Serial.begin(9600);
}

void loop() {
  pinMode(coilPin, OUTPUT);
  digitalWrite(coilPin, HIGH);
  delayMicroseconds(100);

  pinMode(coilPin, INPUT);
  duration = pulseIn(coilPin, HIGH);

  Serial.println(duration);

  if (duration > threshold) {
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }
}

