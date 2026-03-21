# include<Wire.h>
float volt_input = A1;

float r2 = 220;
float r1 = 1000;
float calibration_factor = 0.88;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
float vout = analogRead(volt_input);  // put your main code here, to run repeatedly:
float voltage = vout * 5/1023;
float v = voltage *(r1 + r2)/r2;
v = v * calibration_factor;
Serial.print("voltage : ");
Serial.println(v);
delay(500);
}



