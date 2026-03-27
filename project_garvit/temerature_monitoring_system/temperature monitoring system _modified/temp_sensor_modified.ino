const int LM35_PIN     = A0;
const int POT_PIN      = A1;
const int RELAY_PIN    = 7;
const int LED_GREEN    = 0;
const int LED_RED      = 1;

const float TEMP_MIN   = 25.0;
const float TEMP_MAX   = 60.0;
const float HYSTERESIS = 3.0;

bool  fanState         = false;
unsigned long lastLog  = 0;
const int LOG_INTERVAL = 1000;

//Average 10 reading from the temperature sensor
float readTemp() {
  int sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += analogRead(LM35_PIN);
    delay(5);
  }
  float avg     = sum / 10.0;
  float voltage = (avg / 1023.0) * 5.0;
  return voltage * 100.0;
}

//Average 10 reading from the potentiometer 
float readThreshold() {
  int sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += analogRead(POT_PIN);
    delay(5);
  }
  float avg = sum / 10.0;
  return map((int)(avg * 10), 0, 10230, (int)(TEMP_MIN * 10), (int)(TEMP_MAX * 10)) / 10.0;
}

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED,   OUTPUT);

  digitalWrite(RELAY_PIN, HIGH);
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_RED,   LOW);

  Serial.begin(9600);
  Serial.println("System ready.");
  Serial.println("TEMP(C), THRESHOLD(C), STATUS");
}

void loop() {
  float tempC     = readTemp();
  float threshold = readThreshold();

  // Hysteresis control
  if (!fanState && tempC >= threshold) {
    fanState = true;
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(LED_RED,   HIGH);
    digitalWrite(LED_GREEN, LOW);
    Serial.println(">> Fan turned ON");
  }
  else if (fanState && tempC <= (threshold - HYSTERESIS)) {
    fanState = false;
    digitalWrite(RELAY_PIN, HIGH);
    digitalWrite(LED_RED,   LOW);
    digitalWrite(LED_GREEN, HIGH);
    Serial.println(">> Fan turned OFF");
  }

  //  Serial displaying in every 1 second 
  if (millis() - lastLog >= LOG_INTERVAL) {
    lastLog = millis();
    Serial.print("TEMP:");
    Serial.print(tempC, 1);
    Serial.print(",THRESHOLD:");
    Serial.print(threshold, 1);
    Serial.print(",STATUS:");
    Serial.println(fanState ? "FAN_ON" : "FAN_OFF");
  }
}

