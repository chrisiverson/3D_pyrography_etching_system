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
void setup(){
  
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

  pinMode(38, OUTPUT); //Enable    // old 6
  pinMode(54, OUTPUT); //Step      // old 5
  pinMode(55, OUTPUT); //Direction // old 4

  digitalWrite(38,LOW);
  
}

void loop(){

  UD = analogRead(IUP);
  LR = analogRead(ILR);
  // UP-DOWN
  if(UD < UPMID - MID){
   digitalWrite(DWN, LOW);
  }else{
   digitalWrite(DWN, HIGH);
  }
  
  if(UD > UPMID + MID){
   digitalWrite(UP, LOW);
  }else{
   digitalWrite(UP, HIGH);
  }
  // LEFT-RIGHT

  //LEFT
  if(LR < LRMID - MID){
   digitalWrite(55,LOW);
   digitalWrite(LEFT, LOW);
   digitalWrite(54,HIGH);
   delayMicroseconds(500);
   
  }else{
   digitalWrite(54,LOW);
   digitalWrite(LEFT, HIGH);
  }

  //RIGHT
  if(LR > LRMID + MID){
   digitalWrite(55,HIGH);
   digitalWrite(RT, LOW);
   digitalWrite(54,HIGH);
   delayMicroseconds(500);
   
  }else{
   digitalWrite(54,LOW);
   digitalWrite(RT, HIGH);
  }
 
  //delay(200);


}