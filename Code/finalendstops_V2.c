/*
2-axis joystick connected to an Arduino Micro
to output 4 pins, up, down, left & right
If you are using pull down resistors, change all the HIGHs to LOWs and LOWs to HIGH.
This skectch is using pull up resistors.
*/


String readString;



int UD = 0;
int LR = 0;
/* Arduino Micro output pins*/
int DWN = 27;
int UP = 29;
int LEFT = 31;
int RT = 33;
/* Arduino Micro Input Pins */
int IUP=59;//A5
int ILR=63;//A9

int MID = 33; // 33 mid point delta arduino, use 4 for attiny
int LRMID = 0;
int UPMID = 0;
char randomflag = 0;

const int x_endstopPin_min = 3; // endstop for x-axis (min)
const int x_endstopPin_max = 2; // endstop for x-axis (max)

const int y_endstopPin_min = 14; // endstop for y-axis (min)
const int y_endstopPin_max = 15; // endstop for y-axis (max)

const int z_endstopPin = 18; //endstop for z-axis

const int buttonPin = 47; //D47    // the number of the pushbutton pin
const int buttonPin2 = 32; //D32
const int ledPin =  23;      // the number of the LED pin

int buttonState = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;

int x_endstopState_min = 0; //these states will contain value from reading input values
int x_endstopState_max = 0;
int y_endstopState_min = 0;
int y_endstopState_max = 0;
int z_endstopState = 0;


void setup(){
 
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);


  pinMode(x_endstopPin_min, INPUT);
  pinMode(x_endstopPin_max, INPUT);
  pinMode(y_endstopPin_min, INPUT);
  pinMode(y_endstopPin_max, INPUT);
  pinMode(z_endstopPin, INPUT);
  
  pinMode(DWN, OUTPUT);
  pinMode(UP, OUTPUT);  
  pinMode(LEFT, OUTPUT); 
  pinMode(RT, OUTPUT);

   
  digitalWrite(DWN, HIGH);
  digitalWrite(UP, HIGH);
  digitalWrite(LEFT, HIGH);
  digitalWrite(RT, HIGH);
  
  //calabrate center
  LRMID = analogRead(ILR);
  UPMID = analogRead(IUP);

  pinMode(38, OUTPUT); //Enable X   // old 6
  pinMode(54, OUTPUT); //Step   X   // old 5
  pinMode(55, OUTPUT); //Direction // old 4


  pinMode(56, OUTPUT);// Enable Y
  pinMode(60, OUTPUT);// Step Y
  pinMode(61, OUTPUT);// Direction Y
  //digitalWrite(38,LOW);
  
  pinMode(62, OUTPUT);// Enable Z
  pinMode(46, OUTPUT);// Step Z
  pinMode(48, OUTPUT);// Direction Z
  
 

}

void loop(){

  while (Serial.available()) {
    delay(3);  
    char c = Serial.read();
    readString += c; 
  }
//***********************************BLUETOOTH BEGIN*****************
if (readString.length() >0) {
    Serial.println(readString);
    
    
    if(readString == "UP")
    {
      randomflag = 1;
    }
    else if (readString == "off")
    {
      randomflag = 0;
    }
    
    
    readString="";
  }
//***********************************BLUETOOTH END*******************



  x_endstopState_min  = digitalRead(x_endstopPin_min); //this obtains the "1" or "0" from endstop signal
  x_endstopState_max  = digitalRead(x_endstopPin_max);
  y_endstopState_min  = digitalRead(y_endstopPin_min);
  y_endstopState_max  = digitalRead(y_endstopPin_max);
  z_endstopState = digitalRead(z_endstopPin);
  
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);

  
  UD = analogRead(IUP);
  LR = analogRead(ILR);
  
  //z-direction button UP
  int buttonvar = buttonState;
  int buttonvar2 = buttonState2;

  int x_endstopvar_min = x_endstopState_min; 
  int x_endstopvar_max = x_endstopState_max; 
  int y_endstopvar_min = y_endstopState_min; 
  int y_endstopvar_max = y_endstopState_max;  
  int z_endstopvar = z_endstopState; 
  
  
if (!buttonvar) 
{
    // turn LED on:
  
   digitalWrite(48,LOW);//direction
   digitalWrite(46,HIGH);//step
   digitalWrite(46,LOW);//step
   delayMicroseconds(200);
   
} 

else if(buttonvar)
{
   digitalWrite(46,LOW);
}

if (!buttonvar2 && z_endstopvar) 
{
    // turn LED on:
   digitalWrite(ledPin, HIGH);
  // Serial.println("LED on");
    
   digitalWrite(48,HIGH);//direction
   digitalWrite(46,HIGH);//step
   digitalWrite(46,LOW);//step
   delayMicroseconds(200);
}  

 else if(buttonvar || buttonvar2)
{
   digitalWrite(46,LOW);
} 
  
  
  
  // y-direction UP
  if(((UD < UPMID - MID) || (randomflag ==1)) && (y_endstopvar_min)){
   digitalWrite(DWN, LOW);
   digitalWrite(61,LOW);
   digitalWrite(UP, LOW);
   digitalWrite(60,HIGH);
   delayMicroseconds(200);
   
  }
  else
  {
   digitalWrite(DWN, HIGH);
   digitalWrite(60,LOW);
  }
  // y-direction DOWN
  if((UD > UPMID + MID) && (y_endstopvar_max)){
   digitalWrite(UP, LOW);
   digitalWrite(61,HIGH);
   //digitalWrite(DWN, LOW);
   digitalWrite(60,HIGH);
   delayMicroseconds(200);
  }
  else
  {
   digitalWrite(UP, HIGH);
   digitalWrite(60,LOW);
  }
  // LEFT-RIGHT

  //x-direciton LEFT
  if((LR < LRMID - MID) && x_endstopvar_max){// min
    
   digitalWrite(55,LOW);
   //digitalWrite(LEFT, LOW);// LEDS
   digitalWrite(54,HIGH);
   delayMicroseconds(200);
   
  }
  else{
   digitalWrite(54,LOW);
   digitalWrite(LEFT, HIGH);
  }

  //x-direction RIGHT
  if((LR > LRMID + MID) && x_endstopvar_min){
   digitalWrite(55,HIGH);
   //digitalWrite(RT, LOW);
   digitalWrite(54,HIGH);
   delayMicroseconds(200);
   
  }else{
   digitalWrite(54,LOW);
   digitalWrite(RT, HIGH);
  }
 
 /*
  //x-direciton LEFT
  if(LR < LRMID - MID){
   digitalWrite(48,LOW);
   digitalWrite(LEFT, LOW);
   digitalWrite(46,HIGH);
   delayMicroseconds(200);
   
  }
  else{
   digitalWrite(46,LOW);
   digitalWrite(LEFT, HIGH);
  }

  //x-direction RIGHT
  if(LR > LRMID + MID){
   digitalWrite(48,HIGH);
   digitalWrite(RT, LOW);
   digitalWrite(46,HIGH);
   delayMicroseconds(200);
   
  }else{
   digitalWrite(46,LOW);
   digitalWrite(RT, HIGH);
  }
 */
 
 
 
  //delay(200);


}