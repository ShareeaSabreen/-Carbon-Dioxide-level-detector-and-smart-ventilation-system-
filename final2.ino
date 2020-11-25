#include <LiquidCrystal.h>
#include <Servo.h>
//int servoWindowPin = 9;
int servoOxyPin = 11;
Servo servoWindow;
Servo servoOxy;
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int co2 = 0;
void setup() {
  Serial.begin(9600);
  lcd.begin(20, 4);
  lcd.print("CO2 DETECTOR");
//  servoWindow.attach(servoWindowPin);
  servoOxy.attach(servoOxyPin);
}

void loop() {
  co2 = analogRead(0);
  //Serial.println(co2);
  lcd.setCursor(0, 1);
  lcd.print(co2);
  if (co2 > 500) {
    //delay(1000);
    servoOxy.write(0);
    Serial.println(co2);
    lcd.setCursor(0, 2);
    lcd.print("DANGEROUS!");
  }
  
  else {
   // delay(1000);
    servoOxy.write(90);
    
    Serial.println(co2);
    //servoOxy.write (180);
    //servoOxy.write (90);
    lcd.setCursor(0, 2);
    //lcd.clear();
    //lcd.print("                    ");
    lcd.print("ALL GOOD      ");
    delay(1000);
  }
  
}
