#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
int input = 0;
void setup()
{
  lcd.begin(16,2);
  lcd.clear();
  Serial.begin(9600);       //Start serial communication at 9600bps
  
  pinMode(9, OUTPUT);
  
}

void loop()
{

        lcd.clear();

        // send data only when you receive data:
        if (Serial.available() > 0) 
        {
                // read the incoming byte:
               input = Serial.read();

        }

        if(input == 5)
        {
          lcd.clear();
          lcd.print("Resetting");
          lcd.setCursor(0, 1);
          lcd.print("Platform");
          delay(200);
        }
        else if (input == 6)
        {
          lcd.clear();
          lcd.print("Platform reset");
          delay(200);
        }
        else if (input == 7)
        {
          lcd.clear();
          lcd.print("Centering...");
          delay(200);
        }
        else if (input == 8)
        {
          lcd.clear();
          lcd.print("Centered.");
          delay(200);
        }
        else if (input == 9)
        {
          lcd.clear();
          lcd.print("Drawing diamonds...");
          delay(200);
        }
        else if (input == 10)
        {
          lcd.clear();
          lcd.print("Diamonds");
          lcd.setCursor(0, 1);
          lcd.print("Complete");
          delay(5000);
          input = 0;
        }
        else if (input == 0)
        {
          lcd.clear();
          lcd.print("Printer ready");
          lcd.setCursor(0, 1);
          lcd.print("Joystick enabled");
          delay(100);

          Serial.write(11);
     
        }

        
        

}



