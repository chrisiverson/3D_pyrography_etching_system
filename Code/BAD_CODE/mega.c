#include "image_data.h"

// 0 - Reset then manual, 1 - Image data, 2 - Manual instant
int image_choice = 0;

// 0 - Machine off, 1 - Running startup script, 2 - reset, 3 - calibrating Z axis, 4 - 
int machine_state = 0;

int drawing_image = 0;
int current_step = 0;

String readString;

int step_done = 1;

int automatic = 1;
int UD = 0;
int LR = 0;

int z_with_object_ht = 5000;

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

/////////////////////////////////////////////// RELAY SWITCH VARIABLE //////////////////////////////
int inPin = 25;         // button
int outPin = 39;       // relay

int state_relay = HIGH;      // the current state of the output pin
int relay_var;           // the current reading from the input pin
int previous = LOW;    // the previous reading from the input pin

long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers


const int x_endstopPin_min = 3; // endstop for x-axis (min)
const int x_endstopPin_max = 2; // endstop for x-axis (max)

const int y_endstopPin_min = 14; // endstop for y-axis (min)
const int y_endstopPin_max = 15; // endstop for y-axis (max)

const int z_endstopPin_min = 18; // endstop for z-axis (min)
const int z_endstopPin_max = 19; // endstop for z-axis (max)

const int z_endstopPin_cal = 45; // endstop for z-axis (calibration)

const int buttonPin = 47; //D47    // the number of the pushbutton pin
const int buttonPin2 = 32; //D32
const int ledPin =  23;      // the number of the LED pin

int buttonState = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;

int x_endstopvar_min = 0; //these states will contain value from reading input values
int x_endstopvar_max = 0;
int y_endstopvar_min = 0;
int y_endstopvar_max = 0;
int z_endstopvar_min = 0;
int z_endstopvar_max = 0;
int z_endstopvar_cal = 0;


int temperature_ready =0;

////////////////////// COMMUNICATION VARIABLES //////////////////
int percentage_complete = 0;
int past_percentage = 0;
////////////////////// COMMUNICATION VARIABLES //////////////////

///////////////////////////////////////DELAY VARIABLES//////////////////////////////////////
int automatic_delay_speed = 250;
int manual_delay_speed = 500;


//////////////////////////////INPUTS///////////////////////////////////
int XL = 0;
int XR = 0;
int YU = 0;
int YD = 0;
int ZU = 0;
int ZD = 0;

int readinput = 0;

/////////////////////////////////////////////// RESET FUNCTION //////////////////////////////////
int at_origin = 0;
int actually_reset = 0;

void resetfunction()
{
  if(at_origin == 0 && machine_state == 0)
  {
    Serial2.write(5);
    XL = 10000;
    YD = 10000;
    ZU = 10000;
  }
  else if (machine_state == 0 && at_origin == 1)
  {    
    XL = 0;
    YD = 0;
    YU = 5500;
    XR = 1100;
    machine_state = 2;
  }
  
  return;
}

/////////////////////////////////////////////// CENTER FUNCTION //////////////////////////////////
int running_center = 0;
int centered = 0;
void centerfunction()
{
  //Serial.println("Function called");
  //Serial.println(XR);

    
    
    if (running_center == 0)
    {
      XR = 4000;
      YU = 4000;
      running_center =1;
      //Serial.println("Centering...");
      Serial2.write(7);
    }
    if (XR == 0 && YU == 0)
    {
      centered=1;
      running_center=0;
      //Serial.println("Centered\n");
      automatic = 0;
      Serial2.write(8);
      delay(500);
    }
  
  return;
}



void setup(){

  if (image_choice == 2)
  {
    automatic = 0;
    machine_state= 6;
  }

pinMode(inPin, INPUT);
pinMode(outPin, OUTPUT);

 
  Serial.begin(9600);      // start serial communication at 9600bps
  Serial2.begin(9600);     // start serial1 communication at 9600bps

  

  
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);


  pinMode(x_endstopPin_min, INPUT);
  pinMode(x_endstopPin_max, INPUT);
  pinMode(y_endstopPin_min, INPUT);
  pinMode(y_endstopPin_max, INPUT);
  pinMode(z_endstopPin_min, INPUT);
  pinMode(z_endstopPin_max, INPUT);
  pinMode(z_endstopPin_cal, INPUT);
  
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

  //pinMode(38, OUTPUT); //Enable X   
  pinMode(54, OUTPUT); //Step   X   
  pinMode(55, OUTPUT); //Direction 

  //pinMode(56, OUTPUT);// Enable Y
  pinMode(60, OUTPUT);// Step Y
  pinMode(61, OUTPUT);// Direction Y
  
  //pinMode(62, OUTPUT);// Enable Z
  pinMode(46, OUTPUT);// Step Z
  pinMode(48, OUTPUT);// Direction Z
  
}

void loop(){

  //Serial.println(machine_state);

  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);

  UD = analogRead(IUP);
  LR = analogRead(ILR);
  
  if (UD < (UPMID+20) && (UD > (UPMID-20)))// original  = (UPMID-10)
      UD = UPMID;
  if (LR < (LRMID+20) && (LR > (LRMID-20)))
      LR = LRMID;
  
  int buttonvar = buttonState;
  int buttonvar2 = buttonState2;

  int x_endstopvar_min = digitalRead(x_endstopPin_min); //this obtains the "1" or "0" from endstop signal
  int x_endstopvar_max = digitalRead(x_endstopPin_max);
  int y_endstopvar_min = digitalRead(y_endstopPin_min);
  int y_endstopvar_max = digitalRead(y_endstopPin_max);
  int z_endstopvar_min = digitalRead(z_endstopPin_min);
  int z_endstopvar_max = digitalRead(z_endstopPin_max); 
  int z_endstopvar_cal = digitalRead(z_endstopPin_cal);

if(Serial2.available() > 0)
{
  readinput = Serial2.read();
  /*if(readinput == 20)
  {
    temperature_ready = 1;
  }
  else if(readinput == 21)
  {
    temperature_ready = 0;
  }*/
}

////////Checks if all directional movements have finished
if (XR == 0 && XL == 0 && YU == 0 && YD == 0)
{
  step_done = 1;
}
else
{
  step_done = 0;
}

//////////Checks if the platform is at the origin
if ((x_endstopvar_min == 0) && (y_endstopvar_max == 0))
{
  at_origin = 1;
}
else if ((x_endstopvar_min == 1) || (y_endstopvar_max ==1))
{
  at_origin = 0;
}

////////////////////RESET///////////////////////
if (machine_state < 6)
{
  
if (machine_state == 0)
{
  
   resetfunction();
}
else if ( step_done && machine_state == 2 && z_endstopvar_cal && machine_state == 2)
{
    ZU = 0;
    ZD = 10000;
    machine_state = 3;
}
else if ( step_done && machine_state == 3 && !z_endstopvar_cal)
{
  ZU = 10000;
  XL = 1000;
  YD = 5000;
  ZD = 0;
  z_with_object_ht = 0;
  machine_state = 4;
}
else if (ZD == 0 && step_done && machine_state == 4 && z_endstopvar_cal && !z_endstopvar_max && image_choice == 0)
{
  automatic = 0;
  ZD = 0;
  ZU = 0;
  machine_state = 6;
  Serial2.write(6);
}
else if (ZD == 0 && step_done && machine_state == 4 && z_endstopvar_cal && !z_endstopvar_max && image_choice == 1)
{
  automatic = 2;
  ZD = 0;
  ZU = 0;
  machine_state = 5;
  Serial2.write(6);
}
else if (automatic == 2 && buttonvar2 && machine_state == 5)
{
  automatic = 1;
  machine_state = 7;
}
}


///////////////////////AUTO-IMAGE DRAWING/////////////////////////////
else if(machine_state == 7 || machine_state == 8)
{
if (machine_state == 8 && step_done)
{
    XL = 10*move_list[(num_of_steps-current_step)*4];
    XR = 10*move_list[((num_of_steps-current_step)*4)+1];
    YD = 10*move_list[((num_of_steps-current_step)*4)+2];
    YU = 10*move_list[((num_of_steps-current_step)*4)+3];
    
    current_step--;
    percentage_complete = (100 - ((float(current_step) / float(num_of_steps))*100) + (150));
    
    
    if((percentage_complete != past_percentage) && (percentage_complete > 150) && (percentage_complete % 2))
    {
      Serial2.write(percentage_complete);
      //Serial.println(percentage_complete);
      past_percentage = percentage_complete;
    }
    else if (current_step == 0 && machine_state == 8)
    {
      machine_state = 6;
      automatic = 0;
      percentage_complete = 250;
      Serial2.write(percentage_complete);
    }
}
else if (image_choice == 1 && machine_state == 7)
{
  machine_state = 8;
  current_step = sizeof(move_list)/8;
}


}

/*
  while (Serial.available()) {
    delay(3);  
    char c = Serial.read();
    readString += c; 
  }

*/

///////////////////////////////////BLUETOOTH BEGIN/////////////////////////////////
if (readString.length() >0) 
{
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

//**************************Automatic control*********************//
 if(automatic == 1)
  {
    if (ZU > 0 && z_endstopvar_max) 
{
    // turn LED on:
  z_with_object_ht++;
   digitalWrite(48,LOW);//direction
   digitalWrite(46,HIGH);//step
   digitalWrite(46,LOW);//step
} 

else if(!buttonvar)
{
   digitalWrite(46,LOW);
}

if (ZD > 0 && z_endstopvar_min && z_endstopvar_cal && z_with_object_ht > 0) 
{
  z_with_object_ht--;
    // turn LED on:
   digitalWrite(ledPin, HIGH);
  // Serial.println("LED on");
    
   digitalWrite(48,HIGH);//direction
   digitalWrite(46,HIGH);//step
   digitalWrite(46,LOW);//step   
   //delayMicroseconds(200);
}  

 else if(!buttonvar/* || !buttonvar2*/)
{
   digitalWrite(46,LOW);
} 

  // y-direction UP
  if(((((randomflag ==1)) || (YU > 0)) && y_endstopvar_min ) && (readinput == 0  )){
   digitalWrite(DWN, LOW);
   digitalWrite(61,LOW);
   digitalWrite(UP, LOW);
   digitalWrite(60,HIGH);
   //delayMicroseconds(200);
   //YUCount++;
   YU--;
    }
  else
  {
   digitalWrite(DWN, HIGH);
   digitalWrite(60,LOW);
  }
  // y-direction DOWN
  if((((YD > 0) && y_endstopvar_max )) && (readinput == 0))
  {
   digitalWrite(UP, LOW);
   digitalWrite(61,HIGH);
   //digitalWrite(DWN, LOW);
   digitalWrite(60,HIGH);
   //delayMicroseconds(200);
   //YUCount--;
   YD--;
  }
  else
  {
   digitalWrite(UP, HIGH);
   digitalWrite(60,LOW);
  }
  // LEFT-RIGHT

  //x-direciton RIGHT
  if(((((XR > 0)) && x_endstopvar_max )) && (readinput == 0))
  {// min
    
   digitalWrite(55,HIGH);
   //digitalWrite(LEFT, LOW);// LEDS
   digitalWrite(54,HIGH);
   //delayMicroseconds(200);
   //XRCount++;
   XR--;
  }
  else{
   digitalWrite(54,LOW);
   digitalWrite(LEFT, HIGH);
  }

  //x-direction LEFT
  if(((((XL > 0)) && x_endstopvar_min )) && (readinput == 0))
  {
   digitalWrite(55,LOW);
   //digitalWrite(RT, LOW);
   digitalWrite(54,HIGH);
   //delayMicroseconds(200);
   //XRCount--;
   XL--;
  }else{
   digitalWrite(54,LOW);
   digitalWrite(RT, HIGH);
  }
  delayMicroseconds(automatic_delay_speed);
  }
  else
  {

 //***************MANUAL CONTROl*******************//

 if (buttonvar && z_endstopvar_max) 
{
    // turn LED on:
   z_with_object_ht++;
   digitalWrite(48,LOW);//direction
   digitalWrite(46,HIGH);//step
   digitalWrite(46,LOW);//step
} 

else if(!buttonvar)
{
   digitalWrite(46,LOW);
}

if (buttonvar2 && z_endstopvar_min && z_endstopvar_cal && z_with_object_ht > 0) 
{
   z_with_object_ht--;
   digitalWrite(ledPin, HIGH);
   digitalWrite(48,HIGH);//direction
   digitalWrite(46,HIGH);//step
   digitalWrite(46,LOW);//step   
}  

 else if(!buttonvar)
{
   digitalWrite(46,LOW);
} 
  if(((((UD < UPMID - MID) || (randomflag ==1)) || (YU > 0)) && y_endstopvar_min )){
   digitalWrite(DWN, LOW);
   digitalWrite(61,LOW);
   digitalWrite(UP, LOW);
   digitalWrite(60,HIGH);
   YU--;
    }
  else
  {
   digitalWrite(DWN, HIGH);
   digitalWrite(60,LOW);
  }
   if(((((UD > UPMID + MID) || (YD > 0)) && y_endstopvar_max )))
  {
   digitalWrite(UP, LOW);
   digitalWrite(61,HIGH);
   //digitalWrite(DWN, LOW);
   digitalWrite(60,HIGH);
   YD--;
  }
  else
  {
   digitalWrite(UP, HIGH);
   digitalWrite(60,LOW);
  }
  //******************LEFT-RIGHT*******************//
  if(((((LR < LRMID - MID) || (XR > 0)) && x_endstopvar_max )))
  {
   digitalWrite(55,HIGH);
   digitalWrite(54,HIGH);
   XR--;
  }
  else{
   digitalWrite(54,LOW);
   digitalWrite(LEFT, HIGH);
  }
  if(((((LR > LRMID + MID) || (XL > 0)) && x_endstopvar_min )))
  {
   digitalWrite(55,LOW);
   digitalWrite(54,HIGH);
   XL--;
  }else{
   digitalWrite(54,LOW);
   digitalWrite(RT, HIGH);
  }
delayMicroseconds(manual_delay_speed);
  }
  
 //**********************Relay****************************//
  relay_var = digitalRead(inPin);
  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if (relay_var == HIGH && previous == LOW && millis() - time > debounce) 
  {
    if (state_relay == HIGH)
      state_relay = LOW;
    else
      state_relay = HIGH;

    time = millis();    
  }
  digitalWrite(outPin, state_relay);
  previous = relay_var;

}