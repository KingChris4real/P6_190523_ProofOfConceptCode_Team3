// Arduino-IRremote library will be added
#include <IRremote.h>
#include <IRremoteInt.h>
  
// You can declare the input pin for the signal output of the KY-022 here
int RECV_PIN = 7;
int laserPin = 8;
// Arduino-IRremote library will be initialized
IRrecv irrecv(RECV_PIN);
decode_results results;
  
void setup(){
  Serial.begin(9600);
  pinMode(laserPin, OUTPUT);
  digitalWrite(laserPin, HIGH);
  irrecv.enableIRIn(); // Infrared receiver will start
}
  
// main program loop
void loop() {
    
  // It will be checked if the receiver has gotten a signal.
  if (irrecv.decode(&results)) {
    //At signal input, the received and decoded signal will show via serial console.
    Serial.println(results.value, HEX);
    irrecv.resume(); 
  }
}
