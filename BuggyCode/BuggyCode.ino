// set pins for infrared sensors
const int LEYE = A5;
const int REYE = A1;

// set pins connected to H-bridge to control motor
const int S1 = 6;
const int S2 = 2;
const int S3 = 5;
const int S4 = 3;

// speeds for motors
const int high_speed = 255;
const int medium_speed = 170;
const int low_speed = 80;

void setup() {
  Serial.begin(9600);

  pinMode( LEYE, INPUT );
  pinMode( REYE, INPUT );

  pinMode( S1, OUTPUT );
  pinMode( S2, OUTPUT );
  pinMode( S3, OUTPUT );
  pinMode( S4, OUTPUT );
}

void loop() {
  if(digitalRead( LEYE )== LOW ){
    analogWrite( S4, 50 );
    analogWrite( S3, 0 );
  }
  else{
    analogWrite( S3, 0 );
    analogWrite( S4, 0 );
  }
  
   if(digitalRead( REYE ) == LOW ){
    analogWrite( S1, 255 );
    analogWrite( S2, 0 );
  }
  else{
    analogWrite( S1, 0 );
    analogWrite( S2, 0 );
  }
}
