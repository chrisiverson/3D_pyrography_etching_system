
int UD = 0;
int LR = 0;
/* Arduino Micro output pins*/
int DWN = 13;
int UP = 12;
int LEFT = 11;
int RT = 10;
/* Arduino Micro Input Pins */
int IUP=A0;
int ILR=A1;

int MID = 10; // 10 mid point delta arduino, use 4 for attiny
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
}

void loop(){

  UD = analogRead(IUP);
  LR = analogRead(ILR);

  // UP-DOWN
  if(UD < UPMID - MID){
    
    UD = map(UD,1,1024,1,255); //map for dimness
    analogWrite(DWN,UD);
  }else{
   digitalWrite(DWN, HIGH);
  }
  
  if(UD > UPMID + MID){
    UD = map(UD,1024,1,1,255); //map for dimness
    analogWrite(UP,UD);
  }else{
   digitalWrite(UP, HIGH);
  }
  // LEFT-RIGHT
  if(LR < LRMID - MID){
    UD = map(LR,1,1024,1,255); //map for dimness
    analogWrite(LEFT,UD);
  }else{\
   digitalWrite(LEFT, HIGH);
  }
  
  if(LR > LRMID + MID){
    UD = map(LR,1024,1,1,255); //map for dimness
    analogWrite(RT,UD);
  }else{
   digitalWrite(RT, HIGH);
  }
 


}