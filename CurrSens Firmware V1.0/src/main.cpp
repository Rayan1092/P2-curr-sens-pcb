#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <INA228.h>
#include <Wire.h>

INA228 sens(0x40);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  // put your setup code here, to run once:
  Wire.begin();
  lcd.init();
  lcd.backlight();
  sens.setMaxCurrentShunt(10.0, 0.030);

  lcd.setCursor(0, 0);
  lcd.print("Current Sens V1");

  lcd.setCursor(0, 1);
  lcd.print("Current: ");

  lcd.setCursor(10, 1);
}

void loop()
{
  // put your main code here, to run repeatedly:
  String currVal = String(sens.getCurrent(), 3);

  lcd.setCursor(10, 1);
  lcd.print("      ");

  lcd.setCursor(10, 1);
  lcd.print(currVal);
}
