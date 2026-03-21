#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int current_Pin = A0;
int voltage_Pin = A1;
int R1 = 1000; //1 k ohm resistore
int R2 = 250; // 250 ohm resistor
float voltage = 0;
float current = 0;
float power = 0;
float energy = 0;

unsigned long previous_Time = 0; // will count time that will used in energy

void setup()
{
  lcd.init();
  lcd.backlight();
}

void loop()
{
  int currentValue = analogRead(current_Pin);
  int voltageValue = analogRead(voltage_Pin);

  // Convert to real values (approximation)
  current = (current_Value - 512) * 0.1;
  voltage = voltage_Value * (5.0 / 1023.0) * R2 / (R1 + R2);
  
// calculating power
  power = voltage * current;
  unsigned long current_Time = millis(); // milli() counts time
  float time = (current_Time - previous_Time) / 3600000.0;
// 3600000.0 means number of milli sec in one hour

// calculating energy
  energy += power * time;
  previous_Time = current_Time;
// previous = current means for the next cycle the previous time
//  will be equal to the current time of the previous cycle
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("P:");
  lcd.print(power);

  lcd.setCursor(0,1);
  lcd.print("E:");
  lcd.print(energy);
  delay(1000);
}
