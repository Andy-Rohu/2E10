// set pins for infrared sensors
const int LEYE = A1;
const int REYE = A0;

// set pins connected to H-bridge to control motor
const int S1 = 2;
const int S2 = A5;
const int S3 = A3;
const int S4 = A2;

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
    analogWrite( S1, 50 );
    analogWrite( S2, 0 );
  }
  else{
    analogWrite( S1, 0 );
    analogWrite( S2, 0 );
  }
  
   if(digitalRead( REYE ) == LOW ){
    analogWrite( S3, 0 );
    analogWrite( S4, 100 );
  }
  else{
    analogWrite( S3, 0 );
    analogWrite( S4, 0 );
  }
}
