#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int rollPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply = 0;


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(rollPin, INPUT);
  lcd.print("Press to Roll");
}

void loop() {
  switchState = digitalRead(rollPin);

  if(switchState != prevSwitchState) {
    if(switchState == HIGH) {
      randomSeed(random());
      reply = random(1111);
      Serial.println(reply);
      lcd.clear();
      lcd.setCursor(0,0);
      if(reply >= 0 && reply <= 222) {
        lcd.print("@!%# TG");
      }
      else if(reply > 222 && reply <= 444) {
        lcd.print("8 HONDAS");
      }
      else if(reply > 444 && reply <= 666) {
        lcd.print("WOOOOOOOOOO");
      }
      else if(reply > 666 && reply <= 888) {
        lcd.print("Loose Edge Drive");
      }
      else if(reply > 888 && reply <= 1110) {
        lcd.print("Coffee Time");
      }
      else if(reply == 1111) {
        lcd.print("EASTER EGG");
        lcd.setCursor(0,1);
        lcd.print("Loading...");
        delay(5000);
        lcd.clear();
        lcd.setCursor(3,0);
        lcd.print("github.com");
        lcd.setCursor(0,1);
        lcd.print("/RHEasterEgg/EG");
      }
    }
  }
    prevSwitchState = switchState;
}
