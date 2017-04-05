//Fritzing File: Serial to Serial Connection.fzz

int ledPin = 13;
int board;   // 1 = Uno. 2 = Mega.
int on_off;  // 1 = On. 0 = Off.
int buzzerPin = 9;
int Ack_tx = 2; //Acknowledgement tx.
int rec;


// SETUP *************************************************************************
void setup()
{
  Serial.begin(9600);      // start serial communication at 9600bps
  Serial2.begin(9600);     // start serial1 communication at 9600bps
 
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);




  Serial.flush();
  Serial2.flush();
  
} // End Setup


// LOOP *************************************************************************
void loop()
{

Serial2.write(17);

}  // End Loop.


