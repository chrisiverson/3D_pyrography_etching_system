#include "image_data.h"

// 0 - Hand Control, 1 - Image data, 2 - Diamond
int image_choice = 1;

int ht_chnge = 15;
int image_gain = 13;
int move_now = 1;
int drawing_image = 0;
int current_step = 0;
int image_done = 0;
int z_confirm = 0;

int pen_down = 0;
int pen_change_count = 0;

String readString;

int automatic = 1;
int UD = 0;
int LR = 0;

int z_with_object_ht = 5000;
int reset_step = 0;

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
char BTF = 0;


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
int automatic_delay_speed = 700;
int manual_delay_speed = 500;


//INPUTS
int XL = 0;
int XR = 0;
int YU = 0;
int YD = 0;
int ZU = 0;
int ZD = 0;

/////////////////////////////////////DIAMOND SHIT//////////////////////////////////
int XL1 = 1000;
int XR1 = 0;
int YU1 = 0;
int YD1 = 1000;
int ZU1 = 0;
int ZD1 = 0;

int XL2 = 0;
int XR2 = 1000;
int YU2 = 0;
int YD2 = 1000;
int ZU2 = 0;
int ZD2 = 0;

int XL3 = 1000;
int XR3 = 0;
int YU3 = 0;
int YD3 = 1000;
int ZU3 = 0;
int ZD3 = 0;

int XL4 = 0;
int XR4 = 1000;
int YU4 = 0;
int YD4 = 1000;
int ZU4 = 0;
int ZD4 = 0;

int XL5 = 0;
int XR5 = 1000;
int YU5 = 1000;
int YD5 = 0;
int ZU5 = 0;
int ZD5 = 0;

int XL6 = 1000;
int XR6 = 0;
int YU6 = 1000;
int YD6 = 0;
int ZU6 = 0;
int ZD6 = 0;

int XL7 = 0;
int XR7 = 1000;
int YU7 = 1000;
int YD7 = 0;
int ZU7 = 0;
int ZD7 = 0;

int XL8 = 1000;
int XR8 = 0;
int YU8 = 1000;
int YD8 = 0;
int ZU8 = 0;
int ZD8 = 0;

int XLEND = 0;
int XREND = 0;
int YUEND = 0;
int YDEND = 0;
int ZUEND = 0;
int ZDEND = 0;


int YUCount = 0;
int XRCount = 0;

//Demo pattern
int Done = 1;
int move_num = 0;
int printing = 0;

int readinput = 0;






/////////////////////////////////////////////// RESET FUNCTION //////////////////////////////////
int at_home = 0;
int running_reset = 0;
int reset = 0;
int actually_reset = 0;

void resetfunction()
{
  //Serial.println("Function called");
  //Serial.println(XR);
  if(at_home == 0 && running_reset == 0 && reset == 0)
  {
    running_reset = 1;
    //Serial.println("Reseting the platform...");
    Serial2.write(5);
    XL = 10000;
    YD = 10000;
    ZU = 10000;
  }
  else if (running_reset == 1 && at_home == 1)
  {
    //Serial.println("Platform reset\n");
    
    XL = 0;
    YD = 0;
    YU = 7000;
    XR = 1100;
    running_reset = 0;
    reset = 1;

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

/////////////////////////////////////////////// MOVER FUNCTION //////////////////////////////////
void mover()
{
  
  Done = 0;

    XL = XL1;
    XR = XR1;
    YU = YU1;
    YD = YD1;
    ZU = ZU1;
    ZD = ZD1;

    XL1 = XL2;
    XR1 = XR2;
    YU1 = YU2;
    YD1 = YD2;
    ZU1 = ZU2;
    ZD1 = ZD2;

    XL2 = XL3;
    XR2 = XR3;
    YU2 = YU3;
    YD2 = YD3;
    ZU2 = ZU3;
    ZD2 = ZD3;

    XL3 = XL4;
    XR3 = XR4;
    YU3 = YU4;
    YD3 = YD4;
    ZU3 = ZU4;
    ZD3 = ZD4;

    XL4 = XL5;
    XR4 = XR5;
    YU4 = YU5;
    YD4 = YD5;
    ZU4 = ZU5;
    ZD4 = ZD5;
    
    XL5 = XL6;
    XR5 = XR6;
    YU5 = YU6;
    YD5 = YD6;
    ZU5 = ZU6;
    ZD5 = ZD6;
    
    XL6 = XL7;
    XR6 = XR7;
    YU6 = YU7;
    YD6 = YD7;
    ZU6 = ZU7;
    ZD6 = ZD7;
    
    XL7 = XL8;
    XR7 = XR8;
    YU7 = YU8;
    YD7 = YD8;
    ZU7 = ZU8;
    ZD7 = ZD8;
    
    XL8 = XLEND;
    XR8 = XREND;
    YU8 = YUEND;
    YD8 = YDEND;
    ZU8 = ZUEND;
    ZD8 = ZDEND;
    move_num++;


  return;
}


void setup(){


 
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

  //Serial.println(automatic);

 buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);

  
  UD = analogRead(IUP);
  LR = analogRead(ILR);
  
  if (UD < (UPMID+40) && (UD > (UPMID-40)))// original  = (UPMID-10)
      UD = UPMID;
  if (LR < (LRMID+40) && (LR > (LRMID-40)))
      LR = LRMID;
  
  //z-direction button UP
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
  if(readinput == 20)
  {
    
    temperature_ready = 1;
//    Serial.println("--------");
//    Serial.println(temperature_ready);
//    Serial.println("--------");
  }
  else if(readinput == 21)
  {
    temperature_ready = 0;
//    Serial.println("--------");
//    Serial.println(temperature_ready);
//    Serial.println("--------");
  }
}

////////////////////RESET///////////////////////

if (!actually_reset)
{
if (!reset)
{
   resetfunction();
}

if ( XR == 0 && XL == 0 && YU == 0 && YD == 0 && reset && z_endstopvar_cal && reset_step == 0)
{
    ZU = 0;
    ZD = 10000;
    reset_step = 1;
}

if ( XR == 0 && XL == 0 && YU == 0 && YD == 0 && reset && !z_endstopvar_cal && reset_step == 1)
{
  ZU = 10000;
  XL = 1000;
  YD = 3000;
  ZD = 0;
  z_with_object_ht = 0;
  reset_step = 2;
}

if (YD == 0 && XR == 0 && reset_step == 2 && z_endstopvar_cal && !z_endstopvar_max && image_choice == 0)
{
  automatic = 0;
  ZD = 0;
  ZU = 0;
  actually_reset = 1;
  Serial2.write(127);
  delay(2000);
  Serial2.write(126);
}
else if (YD == 0 && XR == 0 && reset_step == 2 && z_endstopvar_cal && !z_endstopvar_max && image_choice == 1)
{
  automatic = 2;
  ZD = 0;
  ZU = 0;
  actually_reset = 1;
  Serial2.write(127);
}
}

if (z_confirm == 0 && automatic == 2 && buttonvar2 && actually_reset)
{
  z_confirm = 1;
  Serial2.write(8);
}

//Serial.println(temperature_ready);

if (z_confirm && automatic == 2 && buttonvar && actually_reset && temperature_ready)
{
  automatic = 1;
}
  

///////////////////////AUTO-IMAGE DRAWING/////////////////////////////
if (!z_endstopvar_max && !y_endstopvar_max && percentage_complete == 250)
{
      
      delay(2000);
      automatic = 0;
      ZU = 0;
      YD = 0;
      Serial2.write(126);
}

if (actually_reset && image_choice == 1 && drawing_image == 0 && image_done == 0 && automatic == 1)
{
  drawing_image = 1;
  current_step = sizeof(move_list)/4;
  z_with_object_ht = z_with_object_ht +ht_chnge;
        ZD = 300;
        //pen_down = 1;
        //Serial.println(pen_down);
}

if (drawing_image && XR == 0 && XL == 0 && YU == 0 && YD == 0 && image_done == 0)
{
    
    XL1 = image_gain*move_list[(num_of_steps-current_step)*4];
    XR1 = image_gain*move_list[((num_of_steps-current_step)*4)+1];
    YD1 = image_gain*move_list[((num_of_steps-current_step)*4)+2];
    YU1 = image_gain*move_list[((num_of_steps-current_step)*4)+3];
    //Serial.println(XR1);
    if ((XL1 > image_gain || XR1 > image_gain || YD1 > image_gain || YU1 > image_gain) && pen_down && move_now)
    {
      ZD = 0;
      ZU = 300;
      pen_down = 0;
      move_now = 0;
      //Serial.println(ZU);
      
    }
    else if (!pen_down && move_now)
    {
       ZD = 300;
       ZU = 0;
       move_now = 0;
       pen_down = 1;
    }
    else
      move_now = 0;
    
    if (ZD == 0 && ZU == 0 && move_now == 0)
    {
      move_now = 1;
      XL = XL1;
      XR = XR1; 
      YU = YU1;
      YD = YD1;
      current_step--;
    }

        
    percentage_complete = (100 - ((float(current_step) / float(num_of_steps))*100) + (150));
    
    
    if((percentage_complete != past_percentage) && (percentage_complete > 150) && (percentage_complete % 2))
    {
      if ((percentage_complete-150) < 5 || (percentage_complete-150) > 14)
      {
        Serial2.write(percentage_complete);
      }
      //Serial.println(percentage_complete);
      past_percentage = percentage_complete;
    }
    else if (percentage_complete == 250)
    {
      drawing_image = 0;
      image_done = 1;
      ZD = 0;
      ZU = 400;
      YD = 9000;
      percentage_complete = 250;
      Serial.println("Finish");
      Serial2.write(percentage_complete);
      drawing_image = 2;
      automatic_delay_speed = 500;
      z_with_object_ht = z_with_object_ht - ht_chnge;
    }
}




//Serial.println(automatic);





  
// RELAY SWITCH CODE //
///////////////////////////////////BLUETOOTH BEGIN/////////////////////////////////
  while (Serial.available()) {
    delay(3);  
    char c = Serial.read();
    readString += c; 
  }


if (readString.length() >0) {
    Serial.println(readString);
    
    if(readString == "UP")
    {
      BTF = 1;
    }
    else if(readString == "DOWN")
    {
      BTF = 2;
    }
    else if(readString == "LEFT")
    {
      BTF = 4;
    }
    else if(readString == "RIGHT")
    {
      BTF = 3;
    }
    else if(readString == "DR")
    {
      BTF = 5;
    }
    else if(readString == "DL")
    {
      BTF = 6;
    }
    else if(readString == "UR")
    {
      BTF = 7;
    }
    else if(readString == "UL")
    {
      BTF = 8;
    }
    else if(readString == "ZUP")
    {
      BTF = 9;
    }
    else if(readString == "ZDOWN")
    {
      BTF = 10;
    }
    else if(readString == "LIGHT")
    {
      automatic_delay_speed = 300; //faster motor speed --> lighter shade
    }
    else if(readString == "MEDIUM")
    {
      automatic_delay_speed = 500; //use standard delay speed for medium
    }
    else if(readString == "DARK")
    {
      automatic_delay_speed = 800; //slower motor speed --> darker shade
    }
    else if (readString == "off")
    {
      BTF = 0;
    }
    
    
    readString="";
  }

  //Serial.println(z_endstopvar_cal);

if ((x_endstopvar_min == 0) && (y_endstopvar_max == 0))
{
  at_home = 1;
}

else if ((x_endstopvar_min == 1) || (y_endstopvar_max ==1))
{
  at_home = 0;
}  

if (automatic)
{
if ( !z_endstopvar_min || !z_endstopvar_cal || z_with_object_ht == 0 )
{
  ZD = 0;
}
else if (!z_endstopvar_max)
{
  ZU = 0;
}
else if (!y_endstopvar_max)
{
  YD = 0;
}
else if (!y_endstopvar_min)
{
  YU = 0;
}
else if (!x_endstopvar_min)
{
  XL = 0;
}
else if (!x_endstopvar_max)
{
  XR = 0;
}
}
//////////////////???CENTERING CODE/////////////////////////////
/*
  if ((Done && (move_num < 9) && centered) && temperature_ready)
  {
    //Serial.println("yes");
    if (!printing)
    {
      
      //Serial.println("Drawing the diamonds...");
      Serial2.write(9);
    }
   
   mover();
   
   printing = 1;
  }
 */
 
  if ( XR == 0 && XL == 0 && YU == 0 && YD == 0 && printing)
  {
    
    Done = 1;
    if (move_num == 9 && printing)
    {
      printing = 0;
      automatic = 0;
      //Serial.println("Diamonds complete.\n");
      Serial2.write(10);
    }
  }


////////////////////////Automatic control///////////////////////
 if(automatic == 1)
  {
    
    if (ZU > 0 && z_endstopvar_max) 
{
    // turn LED on:
  z_with_object_ht++;
   digitalWrite(48,LOW);//direction
   digitalWrite(46,HIGH);//step
   digitalWrite(46,LOW);//step
   ZU--;
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
   ZD--;
   //pen_down = 1;
   //delayMicroseconds(200);
}  

 else if(!buttonvar/* || !buttonvar2*/)
{
   digitalWrite(46,LOW);
} 

  // y-direction UP
  if((((YU > 0)) && y_endstopvar_min ) && (readinput == 0  || readinput == 20) /*&& move_now*/){
   digitalWrite(DWN, LOW);
   digitalWrite(61,LOW);
   digitalWrite(UP, LOW);
   digitalWrite(60,HIGH);
   //delayMicroseconds(200);
   YUCount++;
   YU--;
    }
  else
  {
   digitalWrite(DWN, HIGH);
   digitalWrite(60,LOW);
  }
  // y-direction DOWN
  if((((YD > 0) && y_endstopvar_max )) && (readinput == 0  || readinput == 20) /*&& move_now*/)
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
  if(((((XR > 0)) && x_endstopvar_max )) && (readinput == 0 || readinput == 20) /*&& move_now*/)
  {// min
   digitalWrite(55,HIGH);
   //digitalWrite(LEFT, LOW);// LEDS
   digitalWrite(54,HIGH);
   //delayMicroseconds(200);
   XRCount++;
   XR--;
  }
  else{
   digitalWrite(54,LOW);
   digitalWrite(LEFT, HIGH);
  }

  //x-direction LEFT
  if(((((XL > 0)) && x_endstopvar_min )) && (readinput == 0 || readinput == 20) /*&& move_now*/)
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
  else if (automatic == 0)
  {

 ///////////////////////// MANUAL CONTROl //////////

 if (((buttonvar) || (BTF == 9)) && z_endstopvar_max)
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

if (((buttonvar2 || (BTF == 10)) && z_endstopvar_min && z_endstopvar_cal && z_with_object_ht > 0))
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
 else
{
   digitalWrite(46,LOW);
} 
// y-direction UP
  if(((((UD > UPMID + MID) || ((BTF == 1) || (BTF == 7)|| (BTF == 8)))) && y_endstopvar_min )){
   digitalWrite(DWN, LOW);
   digitalWrite(61,LOW);
   digitalWrite(UP, LOW);
   digitalWrite(60,HIGH);
   //delayMicroseconds(200);
   YUCount++;
   YU--;
    }
  else
  {
   digitalWrite(DWN, HIGH);
   digitalWrite(60,LOW);
  }
  // y-direction DOWN
   if((((((UD < UPMID - MID) || ((BTF == 2) || (BTF == 5)|| (BTF == 6)) || (YD > 0)) && y_endstopvar_max ))))
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
  //if(((((LR < LRMID - MID) || (XR > 0)) && x_endstopvar_max )) && (temperature_ready))
  if((((((LR > LRMID + MID) || ((BTF == 3)|| (BTF == 5)|| (BTF == 7))) || (XR > 0)) && x_endstopvar_max )))
  {// min
    
   digitalWrite(55,HIGH);
   //digitalWrite(LEFT, LOW);// LEDS
   digitalWrite(54,HIGH);
   //delayMicroseconds(200);
   XRCount++;
   XR--;
  }
  else{
   digitalWrite(54,LOW);
   digitalWrite(LEFT, HIGH);
  }

  //x-direction LEFT
  //if(((((LR > LRMID + MID) || (XL > 0)) && x_endstopvar_min )) && (temperature_ready))
  if((((((LR < LRMID - MID) || (( BTF == 4 )|| (BTF == 6)|| (BTF == 8))) || (XL > 0)) && x_endstopvar_min )))
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
delayMicroseconds(manual_delay_speed);
  }

}