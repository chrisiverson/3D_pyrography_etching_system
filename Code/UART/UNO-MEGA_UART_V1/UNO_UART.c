#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
int testbed = 0;
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
               testbed = Serial.read();

         }
         else
         {
                lcd.print("FUCK");
                delay(300);
         }


         if(testbed == 0)
         {
            digitalWrite(9,LOW);
            
         }
         else if (testbed == 17)
         {
            digitalWrite(9,LOW);
            delay(1000);
            digitalWrite(9,HIGH);
         }
}


