int flag = 0;
int ledPin = 13;                 // LED connected to digital pin 13
byte data = 255;


void setup() {
  Serial.begin(115200);               //initial the Serial
  //  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);      // sets the digital pin as output
//  byte data = 255;
  checkByte(data);

}

void loop()
{
  //  Serial.print("AT+KEY="); Serial.print(1, DEC); Serial.println();
  if (Serial.available() > 0)
  {
    //    Serial.print("AT+KEY="); Serial.print(1, DEC); Serial.println();
    //    byte data = Serial.read();
//    byte data = 255;
    //    Serial.write(data);    //send what has been received
    Serial.println(data, DEC);
    //    Serial.write("1"); // send a byte with the value 45
    checkByte(data);
    //    digitalWrite(ledPin, HIGH);   // sets the LED on
    //    delay(1000);                  // waits for a second
    //    //    int bytesSent = Serial.write("Hello"); //send the string “hello” and return the length of the string.
    //    //    Serial.write(bytesSent);
    flag = 1;
  }
}

void checkByte(byte data) {
  byte incomingByte = data;
  int index;
  for (index = 0; index < 8; index++) {
    if (bitRead(incomingByte, index) == 0) {
      //      if (incomingByte[index] == 1) {
      digitalWrite(ledPin, HIGH);   // sets the LED on
      delay(500);
      digitalWrite(ledPin, LOW);   // sets the LED on
      delay(500);
    }
    else {
      digitalWrite(ledPin, HIGH);   // sets the LED on
      delay(1000);
      digitalWrite(ledPin, LOW);   // sets the LED on

    }
  }
}


