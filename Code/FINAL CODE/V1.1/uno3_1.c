#include <LiquidCrystal.h>
#include <math.h>

int cal_com = 0;
int delay_me = 500;

int inPin = 7;         // button
int outPin = 8;       // relay

int state = LOW;      // the current state of the output pin
int reading = LOW;           // the current reading from the input pin
int previous = LOW;    // the previous reading from the input pin

long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers

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

  pinMode(inPin, INPUT);
  pinMode(outPin, OUTPUT);
  
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
  digitalWrite(outPin, HIGH); //initialize relay to 0 at start of program
  
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
            lcd.print("Printer is  ");
            lcd.print(temp);
          lcd.print((char)223);
          lcd.print("F");
            lcd.setCursor(0, 1);
            lcd.print("powering on ");
            lcd.write(byte(1));
          }
          else 
          {
            digitalWrite(9,LOW);
            not_con_LED =1;
            lcd.clear();
            lcd.print("Printer is  ");
            lcd.print(temp);
          lcd.print((char)223);
          lcd.print("F");
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
          digitalWrite(outPin,LOW);// low means RELAY ON, HIGH means RELAY OFF
          //delay(200);
        }

        
        else if (input == 127)
        {
          
          if (cal_com < 5)
          {
          lcd.clear();
          lcd.print("Calibration");
          lcd.setCursor(0, 1);
          lcd.print("Complete");
          
          //digitalWrite(outPin,LOW);// low means RELAY ON, HIGH means RELAY OFF
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
        else if(input == 126) //manual mode calibration complete
        {
          lcd.clear();
          lcd.print("Manual Mode");
          lcd.setCursor(0, 1);
          lcd.print("Temp: ");
          lcd.print(temp);
          lcd.print((char)223);
          lcd.print("F");
        }
        else if (input == 7)
        {
          lcd.clear();
          lcd.print("Centering...");
          //delay(200);
        }
        else if (input == 8)
        { 
          lcd.clear(); //sets relay on once it enters this loop
          lcd.print("Press blue button");//user presses blue button to confirm print
          lcd.setCursor(0, 1);
          lcd.write(byte(fire_num));
          lcd.write(byte(fire_num1));
          lcd.write(byte(fire_num2));
          //lcd.setCursor(0, 1);
          //lcd.print("Temp: ");
          lcd.print(temp);
          lcd.print((char)223);
          lcd.print("F");

          
          
          if (temp >= 90) //send handshake when temp reaches proper 
          {                //temp  
            Serial.write(20);
           
          
          }
           else if (state == LOW)
            {
                reading = 1; 
            }
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
          lcd.print("Print");
          lcd.setCursor(0, 1);
          lcd.print("Complete");
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
            digitalWrite(outPin, HIGH); //turn off relay once drawing complete
          }

          
          
        }
/*if (state == 1)
{
digitalWrite(outPin, state);
//lcd.clear();

state = 0;
}
    lcd.print(state);  */  


          
     delay(delay_me);

       //if (reading == HIGH && previous == LOW && millis() - time > debounce) {
        //reading = 0;
       //}
    //if (state == HIGH)
      //state = LOW;
    //else
      //state = HIGH;

}