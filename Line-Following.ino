const int LIR = A3; //Setting LIR (left infra red) as the name for pin A3
const int RIR = A2; //Setting RIR (right infra red) as the name for pin A2

//Setting H-bridge pin names as the variables for the connected arduino pins
const int M1A = A6;
const int M2A = A5;
const int M3A = A4;
const int M4A = A7;

void setup() {
  Serial.begin(9600); //Starts the serial port at 9600 baud

  //Setting A3 and A2 as input pins (as they are going to receive information from the IR sensors)
  pinMode(LIR, INPUT);
  pinMode(RIR, INPUT);
  pinMode(M1A, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M3A, OUTPUT);
  pinMode(M4A, OUTPUT);
}

void loop() {
  if (digitalRead(LIR) == LOW){
    digitalWrite(M1A, HIGH);
    digitalWrite(M2A, LOW);
  }
  else {
    digitalWrite(M1A, LOW);
    digitalWrite(M1A, LOW);
  }
as
  if (digitalRead(RIR) == LOW){
    digitalWrite(M3A, LOW);
    digitalWrite(M4A, HIGH);
  }
  else {
    digitalWrite(M3A, LOW);
    digitalWrite(M4A, LOW);
  }
}
