#include <Printers.h>
#include <XBee.h>

int myData = 0;
int const ledpin = 13;

void setup(){
  // Start up our serial port, we configured our XBEE devices for 9600 bps.
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
}

void loop(){
   
  if(Serial.available() > 0){
   
      myData = Serial.read();
     
      if(myData == '1'){
      digitalWrite(ledpin, HIGH);
      Serial.write(myData);
      }
     
      if(myData == '0'){
      digitalWrite(ledpin, LOW);
      Serial.write(myData);
  }
  else{
      Serial.write(myData);
  }
   
}
}

