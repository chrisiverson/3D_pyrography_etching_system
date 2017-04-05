#include <LiquidCrystal.h>
#include <math.h>

int cal_com = 0;
int delay_me = 500;

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

byte sady[8] = {
  B00000,
  B10001,
  B10001,
  B00000,  
  B01110,
  B10001,
  B10001,
};

byte fire1[8] = {
  0b01000,
  0b00100,
  0b00110,
  0b00101,
  0b01101,
  0b10001,
  0b10001,
  0b01110
};

byte fire2[8] = {
  0b00000,
  0b00100,
  0b00010,
  0b00010,
  0b00101,
  0b01001,
  0b01001,
  0b00110
};

byte fire3[8] = {
  0b00010,
  0b00100,
  0b01100,
  0b01010,
  0b10010,
  0b10001,
  0b10001,
  0b01110
};

byte fire4[8] = {
  0b00000,
  0b00010,
  0b00100,
  0b01010,
  0b01010,
  0b10001,
  0b10001,
  0b01110
};

int fire_num = 3;
int fire_num1 = 6;
int fire_num2 = 4;

byte diamond[8] = {
  0b00000,
  0b00000,
  0b00100,
  0b01010,
  0b10001,
  0b01010,
  0b00100,
  0b00000
};


int diamond_emoji = 0;

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
  lcd.createChar(2,sady);
  lcd.createChar(3,fire1);
  lcd.createChar(4,fire2);
  lcd.createChar(5,fire3);
  lcd.createChar(6,fire4);
  lcd.createChar(7,diamond);
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
          if (cal_com < 5)
          {
          lcd.clear();
          lcd.print("Calibration");
          lcd.setCursor(0, 1);
          lcd.print("Complete");
          
          }
          
          else if (cal_com < 10)
          {
          lcd.clear();
          lcd.print("Raise Z screw ");
          }
          else if (cal_com < 13)
          {
          lcd.clear();
          lcd.print("Then press");
          lcd.setCursor(0, 1);
          lcd.print("the white button");
          }
          else if (cal_com > 13)
            cal_com = 5;
            
          cal_com++;
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
          lcd.print("Heating ");
          
          lcd.write(byte(fire_num));
          lcd.write(byte(fire_num1));
          lcd.write(byte(fire_num2));
          lcd.setCursor(0, 1);
          lcd.print("Temp: ");
          lcd.print(temp);
          lcd.print((char)223);
          lcd.print("F");
          
          if (temp >= 80)
               Serial.write(20);
          fire_num++;
          if (fire_num == 7)
          fire_num = 3;
          fire_num1++;
          if (fire_num1 == 7)
          fire_num1 = 3;
          fire_num2++;
          if (fire_num2 == 7)
          fire_num2 = 3;
          //delay(200);
        }
        else if (input == 9)
        {
          lcd.clear();
          lcd.print("Drawing...");
          
          if (diamond_emoji == 1)
          {
            lcd.write(byte(7));
            diamond_emoji = 2;
          }
          else if (diamond_emoji == 2)
          {
            lcd.write(byte(7));
            lcd.write(byte(7));
            diamond_emoji = 0;
          }
          else
            diamond_emoji = 1;
            
          lcd.setCursor(0, 1);
          lcd.print("Temp: ");
          lcd.print(temp);
          lcd.print((char)223);
          lcd.print("F");
          
          if (temp < 80)
          {
              Serial.write(21);
              lcd.clear();
              lcd.print("Print failed ");
              lcd.write(byte(2));
               lcd.setCursor(0, 1);
               lcd.print("Temp below 80");
               lcd.print((char)223);
               lcd.print("F");
          }
          //delay(200);
        }
        else if (input == 10)
        {
          lcd.clear();
          lcd.print("Pr1nt");
          lcd.setCursor(0, 1);
          lcd.print("C0mpl3t3");
          lcd.write(byte(7));
          lcd.write(byte(7));
          delay(1000);
         // input = 11;
        }
        else if (input == 11)
        {
          lcd.clear();
          lcd.print("Printer ready");
          lcd.setCursor(0, 1);
          lcd.print("Temp: ");
          lcd.print(temp);
          lcd.print("F");
          //delay(100);
          Serial.write(11);
          
          
        }
        else if (input >= 150 && input <= 250)
        {
          delay_me = 100;
          input = input - 150;
          lcd.clear();
          lcd.print("Print percent: ");
          lcd.setCursor(0, 1);
          lcd.print(input);
          if(input == 100)
          {
            input = 10;
          }

          
          
        }
     delay(delay_me);
        //input_old = input;
    //}
    /*
    lcd.setCursor(0,8);
    lcd.print(temp);
    delay(500);
    */
    
    //Serial.write((int)temp);
}

