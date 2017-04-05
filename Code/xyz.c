/*
2-axis joystick connected to an Arduino Micro
to output 4 pins, up, down, left & right
If you are using pull down resistors, change all the HIGHs to LOWs and LOWs to HIGH.
This skectch is using pull up resistors.
*/



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



const int buttonPin = 40;     // the number of the pushbutton pin
const int ledPin =  23;      // the number of the LED pin

int buttonState = 0;         // variable for reading the pushbutton status



void setup(){
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
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

  buttonState = digitalRead(buttonPin);

  
  UD = analogRead(IUP);
  LR = analogRead(ILR);
  
  //z-direction button UP
  
if (buttonState == HIGH) 
{
    // turn LED on:
   digitalWrite(ledPin, HIGH);
   Serial.println("LED on");
    
   digitalWrite(48,LOW);//direction
   digitalWrite(46,HIGH);//step

   delayMicroseconds(500);
} 
 else 
 {
    // turn LED off:
   digitalWrite(ledPin, LOW);
   Serial.println("LED off");
   digitalWrite(46,LOW);//step
 
   //delayMicroseconds(500);
 }
  

  
  
  
  
  // y-direction UP
  if(UD < UPMID - MID){
   digitalWrite(DWN, LOW);
   digitalWrite(61,LOW);
   digitalWrite(UP, LOW);
   digitalWrite(60,HIGH);
   delayMicroseconds(500);
  }
  else
  {
   digitalWrite(DWN, HIGH);
   digitalWrite(60,LOW);
  }
  // y-direction DOWN
  if(UD > UPMID + MID){
   digitalWrite(UP, LOW);
   digitalWrite(61,HIGH);
   //digitalWrite(DWN, LOW);
   digitalWrite(60,HIGH);
   delayMicroseconds(500);
  }
  else
  {
   digitalWrite(UP, HIGH);
   digitalWrite(60,LOW);
  }
  // LEFT-RIGHT

  //x-direciton LEFT
  if(LR < LRMID - MID){
   digitalWrite(55,LOW);
   //digitalWrite(LEFT, LOW);// LEDS
   digitalWrite(54,HIGH);
   delayMicroseconds(500);
   
  }
  else{
   digitalWrite(54,LOW);
   digitalWrite(LEFT, HIGH);
  }

  //x-direction RIGHT
  if(LR > LRMID + MID){
   digitalWrite(55,HIGH);
   //digitalWrite(RT, LOW);
   digitalWrite(54,HIGH);
   delayMicroseconds(500);
   
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
   delayMicroseconds(500);
   
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
   delayMicroseconds(500);
   
  }else{
   digitalWrite(46,LOW);
   digitalWrite(RT, HIGH);
  }
 */
 
 
 
  //delay(200);


}