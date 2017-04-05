int ledRT = 13; //RIGHT 
int ledDWN = 10;//DOWN
int ledUP = 11; // UP
int ledLT = 12;// LEFT


String readString;

void setup() {
  Serial.begin(9600);
  pinMode(ledUP, OUTPUT); 
  pinMode(ledDWN, OUTPUT);
  pinMode(ledLT, OUTPUT); 
  pinMode(ledRT, OUTPUT);
}

void loop() {
  while (Serial.available()) {
    delay(3);  
    char c = Serial.read();
    readString += c; 
  }
  if (readString.length() >0) {
    Serial.println(readString);
    
    
    if(readString == "UP")
    {
      digitalWrite(ledUP, HIGH);
    }
    
    else if (readString == "DOWN")
    {
      digitalWrite(ledDWN, HIGH);
    }

    else if (readString == "LEFT")
    {
      digitalWrite(ledLT, HIGH);
    }

    else if (readString == "RIGHT")
    {
      digitalWrite(ledRT, HIGH);
    }

    else if (readString == "UL")
    {
      digitalWrite(ledUP, HIGH);
      digitalWrite(ledLT, HIGH);
    }

    else if (readString == "UR")
    {
      digitalWrite(ledUP, HIGH);
      digitalWrite(ledRT, HIGH);
    }

    else if (readString == "DL")
    {
      digitalWrite(ledDWN, HIGH);
      digitalWrite(ledLT, HIGH);
    }

    else if (readString == "DR")
    {
      digitalWrite(ledDWN, HIGH);
      digitalWrite(ledRT, HIGH);
    }
    
    else
    {
      digitalWrite(ledDWN, LOW);
      digitalWrite(ledRT, LOW);
      digitalWrite(ledUP, LOW);
      digitalWrite(ledLT, LOW);
    }
    readString="";
  } 
}