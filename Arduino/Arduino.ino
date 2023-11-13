//This is the main file of the program. All code should go in here and all 
//include files should go in the headers.h file. 
//
#include "Headers.h"

//Creates an object that can communicate with the serial monitor
SoftwareSerial ss(2,3); //Define the input and output pins           

//global variables
int photoresist = 0;   //defines which pin will be read
float photoresist_bit; //variable where bit value will be stored
float volt;            //variable where voltage value will be stored
XBee xBee = XBee(&ss); //radio class member initialization
Servo servo1;
int voltPrevious = 0;
int rotation = 0;
int vals[180];
float maxVolt = 0;
int maxRotation = 0;
int counter = 0;

//This function runs once when the program starts up
void setup() {
  Serial.begin(115200); //begins computer serial
  ss.begin(XBEE_BAUD);  //begins XBee serial
  xBee.setTimeout(10);  //Sets command timeout
  servo1.attach(7);
  delay(1000);
}

//This function runs until the program is terminated
void loop() {
  // put your main code here, to run repeatedly:
  photoresist_bit = analogRead(photoresist); //reads the bit value of Analog pin0
  volt = photoresist_bit*5/1023;             //converts bit value to voltage
  // xBee.print("Photoresitor Voltage:  ");  //labels solar in XB
  // xBee.println(volt);                     //prints solar voltage to XB
  
  if (counter <= 180) {
    servo1.write(counter); 
    if (volt > maxVolt) {
      maxRotation = counter;
      maxVolt = volt;
    }
  } else {
    servo1.write(maxRotation);
  }
  counter++;
  if (counter == 300) {
    counter = 0;
    maxVolt = 0;
    maxRotation = 0;
  }
  delay(100);
}




