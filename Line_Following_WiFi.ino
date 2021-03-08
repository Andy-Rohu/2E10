#include <WiFiNINA.h>
#include "secrets.h"
WiFiServer server(5200);

WiFiClient myClient;

const int LED = 13;

const int LEYE = A5;
const int REYE = A1;

const int TRIG = A6;
const int ECHO = A7;

const int S1 = 6;
const int S2 = 2;
const int S3 = 5;
const int S4 = 3;

int command = 'S';
int previousCommand = 'S';
int speed = 255;
int distance;
String distanceString;
int duration;
bool object = false;

void start_l(), stop_l(), start_r(), stop_r(), buggyStop(), buggyStart(), allStop();


#include "LineFollowingFunctions.h"
#include "freeControlFunctions.h";

void setup() {
  // start the serial port at 9600 baud
  Serial.begin(9600);

  // set the pins as input or output pins
  pinMode( LED, OUTPUT);
  
  pinMode( LEYE, INPUT );
  pinMode( REYE, INPUT );

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode( S1, OUTPUT );
  pinMode( S2, OUTPUT );
  pinMode( S3, OUTPUT );
  pinMode( S4, OUTPUT );

  WiFi.begin(ssid, pass);
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  server.begin();
}

void loop() {

  myClient = server.available();

    if(myClient.available()){
    command = myClient.read();
    }
    
    if(command <= 0){
      command = previousCommand;
    }
      if(command == 'g'){
      buggyStart();
    }
    
    if(command == 's'){
      buggyStop();
      command = myClient.read();
    }

    if(command == 'l'){
      //Serial.write("hardLeft. ");
      hardLeft();
      command = myClient.read();
    }

    if(command == 'r'){
      //Serial.write("hardRight. ");
      hardRight();
      command = myClient.read();
    }
   
    if(command == 'z'){
      //Serial.write("softLeft. ");
      softLeft();
      command = myClient.read();
    }

    if(command == 'x'){
      //Serial.write("softRight. ");
      softRight();
      command = myClient.read();
    }  
    
    if(command == 't'){
      //Serial.write("reverse. ");
      reverse();
    }

    if(command == 'y'){
      //Serial.write("forward. ");
      forward();
    }

    if(command == 'u'){
      Serial.write("buggyReverse. ");
      buggyReverse();
    }

    previousCommand = command;
    
}
