int ledPin = 13;
int ledPin2 = 12;
String readString;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); 
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  while (Serial.available()) {
    delay(3);  
    char c = Serial.read();
    readString += c; 
  }
  if (readString.length() >0) {
    Serial.println(readString);
    if (readString == "on")     
    {
      digitalWrite(ledPin, HIGH);
    }
    if (readString == "off")
    {
      digitalWrite(ledPin, LOW);
    }
    if (readString == "both")
    {
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin, HIGH);
    }
    if (readString == "both_off")
    {
       digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin, LOW);
    }
    readString="";
  } 
}