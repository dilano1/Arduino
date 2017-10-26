char message[10]; //create an array that can be 10 characters long. if you write something with more than 10 characters you'll get an error
const int ledpin = 13;

void setup() {
  // Start up our serial port, we configured our XBEE devices for 9600 bps.
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
}

void loop() {

  if (Serial.available() > 0) {

    Serial.readBytes(message, 10);//the number here has to match the size of the character array

    if (message[0] == 1) {
      digitalWrite(ledpin, HIGH);
      Serial.write(message, 10);//the number here also has to match the size of the character array
      Serial.println(message);
    }else if (message[0] == 0) {
      digitalWrite(ledpin, LOW);
      Serial.write(message, 10);
      Serial.println(message);
    }else{ 
      Serial.write(message, 10);
      Serial.println(message);
    }
  } else {
    Serial.write(message, 10);
    Serial.println(message);
  }


}
