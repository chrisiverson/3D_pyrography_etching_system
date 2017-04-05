#include <LiquidCrystal.h>
#include <math.h>

byte smiley[8] = {
  B00000,
  B10001,
  B10001,
  B00000,  
  B11111,
  B10001,
  B01110,
};

byte winky[8] = {
  B00000,
  B00001,
  B11001,
  B00000,  
  B11111,
  B10001,
  B01110,
};

double Thermistor(int RawADC) 
{
  double Temp;
  Temp = log(10000.0*((1024.0/RawADC-1))); 
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
  Temp = Temp - 273.15;          
  Temp = (Temp * 9.0)/ 5.0 + 32.0; 
  return Temp;
}

int val;                
double temp;            

LiquidCrystal lcd(12,11,5,4,3,2);
int input = 0;
void setup()
{

  
  lcd.begin(16,2);
  lcd.clear();
  Serial.begin(9600);       //Start serial communication at 9600bps
  Serial.flush();
  lcd.createChar(0, smiley);
  lcd.createChar(1, winky);
  pinMode(9, OUTPUT);
  
}

int not_con_LED = 1;
int input_old = 0;

void loop()
{
        
        val=analogRead(0);      
        temp=Thermistor(val);  

        // send data only when you receive data:
        if (Serial.available() > 0) 
        {
                // read the incoming byte:
               input = Serial.read();
               
               digitalWrite(9,HIGH);
        }

        
     //if (input != input_old)
     //{
        if(input == 0)
        {
          if(not_con_LED){
            digitalWrite(9,HIGH);
            not_con_LED=0;
            lcd.clear();
            lcd.print("Printer is");
            lcd.setCursor(0, 1);
            lcd.print("powering on ");
            lcd.write(byte(1));
          }
          else 
          {
            digitalWrite(9,LOW);
            not_con_LED =1;
            lcd.clear();
            lcd.print("Printer is");
            lcd.setCursor(0, 1);
            lcd.print("powering on ");
            lcd.write(byte(0));
          }
        }
        if(input == 5)
        {
          lcd.clear();
          lcd.print("Calibrating");
          lcd.setCursor(0, 1);
          lcd.print("Platform");
          //delay(200);
        }
        else if (input == 6)
        {
          lcd.clear();
          lcd.print("Calibration");
          lcd.setCursor(0, 1);
          lcd.print("Complete");
          //delay(200);
        }
        else if (input == 7)
        {
          lcd.clear();
          lcd.print("Centering...");
          //delay(200);
        }
        else if (input == 8)
        {
          lcd.clear();
          lcd.print("Ready. Heating.");
          lcd.setCursor(0, 1);
          lcd.print("Temp:");
          lcd.print(temp);
          lcd.print("F");
          lcd.print((char)223);
          if (temp >= 80)
               Serial.write(20);
          //delay(200);
        }
        else if (input == 9)
        {
          lcd.clear();
          lcd.print("Drawing diamonds...");
          lcd.setCursor(0, 1);
          lcd.print("Temp: ");
          lcd.print(temp);
          lcd.print("F");
          lcd.print((char)223);
          if (temp < 80)
          {
              Serial.write(21);
              lcd.clear();
              lcd.print("Print failed...");
               lcd.setCursor(0, 1);
               lcd.print("Temp below 80F");
               lcd.print((char)223);
          }
          //delay(200);
        }
        else if (input == 10)
        {
          lcd.clear();
          lcd.print("Diamonds");
          lcd.setCursor(0, 1);
          lcd.print("Complete");
          delay(1000);
          input = 11;
        }
        else if (input == 11)
        {
          lcd.clear();
          lcd.print("Printer ready");
          lcd.setCursor(0, 1);
          lcd.print("JE  Temp: ");
          lcd.print(temp);
          lcd.print("F");
          //delay(100);
          Serial.write(11);
          
        }
     delay(1000);
        //input_old = input;
    //}

}


