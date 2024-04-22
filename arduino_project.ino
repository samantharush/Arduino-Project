#include <Servo.h>

// push button pin
int buttonPin = 8;

// declare servor pin
int servoPin = 3;

// create servo object
Servo Servo1; 

int pos = 0; // servo position var

long randNum; // random number var

int counter = 0;

void setup() {
  // attach servo to pin
  Servo1.attach(servoPin);
  Serial.begin(9600);
  randomSeed(analogRead(A0)); 

  pinMode(buttonPin, INPUT);
}

void loop() {
  int buttonState; 
  buttonState = digitalRead(buttonPin);

  if(buttonState == LOW){ 
    randNum = random(0, 29);
    Serial.println(randNum);

    for(long i = randNum; i <= randNum ; i++){

      for(int pos = 0; pos <= 180; pos++){
        Servo1.write(pos);
        delay(5);
      }
      for(int pos = 180; pos >= 0; pos--){
        Servo1.write(pos);
        delay(5);
      }
      if((i & 1) == 1){
        Servo1.write(0);
        delay(5);
      }
    }
    //delay(150);
  
    while(1){
        // do nothing
    }
  }
}

