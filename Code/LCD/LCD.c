#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

void setup()
{
  lcd.begin(16,2);
  lcd.clear();
}

void loop()
{
  lcd.print("printing text");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("setting cursor");

  delay(3000);
  
  lcd.clear();
  lcd.noBlink();
  lcd.print("blinking cursor");
  lcd.blink();
  
  delay(3000); 

  lcd.clear();
  
  lcd.print("uline cursor");
  lcd.cursor();

  delay(3000);

  lcd.clear();
  lcd.print("no cursor");
  lcd.noCursor();

  delay(3000);

  lcd.clear();
  lcd.print("no display"); 

  delay(1000);

  lcd.noDisplay();
  lcd.clear();
  lcd.print("display on");

  delay(3000);
  lcd.clear();
  lcd.display();

  delay(3000);
  
}
