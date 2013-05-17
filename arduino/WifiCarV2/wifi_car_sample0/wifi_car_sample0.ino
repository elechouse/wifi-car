#include "Servo.h"
#include "CarDriverShield.h"
#include "BiaxialServo.h"

CarDriverShield myCar;
int led_pin = 13;

BiaxialServo myCamera;
int xy_pin = 7;
int yz_pin = 8;

void setup()
{
  Serial.begin(115200);

#ifdef __DEBUG
  Serial.println("-----------Smart Car --------------\r\n");
#endif

  /** wifi-car initial */
  myCar.begin(led_pin);
  myCamera.begin(xy_pin, yz_pin);
}

void loop()
{
  unsigned char buf;
  /** led control process, must be polled in loop() */
  myCar.evt_loop();

  if(Serial.available()){
    buf=Serial.read();
#ifdef __DEBUG
    Serial.write(buf);
#endif
    switch(buf){
    case 'w': 
    case 'W':
      /** forward */
      myCar.forward();
      break;
    case 's': 
    case 'S':
      /** backward */
      myCar.backward();
      break;
    case 'z': 
    case 'Z':
      /** stop */
      myCar.stop();
      break;
    case 'e': 
    case 'E':
      /** accelerate */
      myCar.accelerate();
      break;
    case 'c': 
    case 'C':
      /** decelerate */
      myCar.decelerate();
      break;
    case 'a': 
    case 'A':
      /** turn left*/
      myCar.turn_left();
      break;
    case 'd': 
    case 'D':
      /** turn right*/
      myCar.turn_right();
      break;

      /** camera control */
    case 'i': 
    case 'I':
      /** camera up */
      myCamera.up();
      break;
    case 'k': 
    case 'K':
      /** camera down */
      myCamera.down();
      break;
    case 'j': 
    case 'J':
      /** camera left */
      myCamera.left();
      break;
    case 'L': 
    case 'l':
      /** camera right */
      myCamera.right();
      break;
    case 'O': 
    case 'o':
      /** center camera */
      myCamera.center();
      break;

    }
  }
}

