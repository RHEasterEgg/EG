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
      reply = random(1666);
      Serial.println(reply);
      lcd.clear();
      lcd.setCursor(0,0);
      if(reply >= 0 && reply <= 277) {
        lcd.print("@!%# TG");
      }
      else if(reply > 277 && reply <= 554) {
        lcd.print("8 HONDAS");
      }
      else if(reply > 554 && reply <= 831) {
        lcd.print("WOOOOOOOOOO");
      }
      else if(reply > 831 && reply <= 1108) {
        lcd.print("Loose Edge Drive");
      }
      else if(reply > 1108 && reply <= 1385) {
        lcd.print("Coffee Time");
      }
      else if(reply > 1385 && reply <= 1662) {
        lcd.print("You got a");
        lcd.setCursor(0,1);
        lcd.print("problem?");
      }
      else if(reply == 1666) {
        lcd.print("EASTER EGG");
        lcd.setCursor(0,1);
        lcd.print("Loading...");
        delay(8000);
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


/* Harris you are a great guy. I apprciate not only everything that you have taught me on the gator
 * but also everything you have inadvertently taught me. To take more responsablitiy and be a more honest person. That hard work pays off and not everyone I work with is an asshole.
 * It suck that you are leaving but i am also extremly happy for you. I'm glad that you turned what you thought would be years into months. I'm not sure if you are like me and would chaulk it up to luck
 * but know that it wasn't luck that got you to where you are and where you are going. It's your constant drive and motivation to be the best you can be at everything you do. I haven't known you for long or been
 * your friend for long but I will miss wasting hours of my life talking about things that most people don't even think about and our Coffee Time.
 * 
 * Anyways, I hope you enjoyed finding this little Easter Egg and I really hope you enjoy your new job. 
 * 
 * Talk Soon,
 * Pinner
 * 6/27/2021 
 */
