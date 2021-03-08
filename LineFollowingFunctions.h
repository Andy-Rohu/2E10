int readLEYE(){
  return(digitalRead(LEYE));
}
int readREYE(){
  return(digitalRead(REYE));
}

void readUSS(){
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration/58;
  distanceString = String(distance);
}


void buggyStart(){
  if(object == false){
    myClient.write("Buggy started. ");
    if(readLEYE() == 0 && readREYE() == 1){
      start_r();
      stop_l();
    }
    if(readLEYE() == 1 && readREYE() == 0){
      start_l();
      stop_r();
    }
    if(readLEYE() == 1 && readREYE() == 1){
      stop_r();
      stop_l();
    }
    if(readLEYE() == 0 && readREYE() == 0){
      start_r();
      start_l();
    }
  }

  readUSS();
  if(distance <= 20){
    object = true;
  }
  else{
    object = false;
  }

  if(object == true){
    allStop();
    myClient.println("Object blocking path (" +distanceString+ " cm)");   
  }
}

void buggyReverse(){
  allStop();
  if(readLEYE() == 1 && readREYE() == 0){
    analogWrite(S2, speed);
    analogWrite(S1, 0);
    delay(200);
    analogWrite(S2, speed);
    analogWrite(S3, speed);
    delay(700);
  }
  if(readLEYE() == 0 && readREYE() == 1){
    analogWrite(S3, speed);
    analogWrite(S4, 0);
    delay(200);
    analogWrite(S2, speed);
    analogWrite(S3, speed);
    delay(700);
  }
  if(readLEYE() == 1 && readREYE() == 1){
    stop_l();
    stop_r();
  }
  if(readLEYE() == 0 && readREYE() == 0){
    analogWrite(S2, speed);
    analogWrite(S3, speed);
  }
  delay(100);
  stop_r();
  stop_l();
}

void buggyStop(){
  if(object == false){
    myClient.write("Buggy stopped. ");
    allStop();
  }
}

void start_r() {
  analogWrite(S3, 0);
  analogWrite(S4, speed);
}

void stop_r() {
  analogWrite(S3, 0);
  analogWrite(S4, 0);
}

void start_l() {
  analogWrite(S1, speed);
  analogWrite(S2, 0);
}

void stop_l() {
  analogWrite(S1, 0);
  analogWrite(S2, 0);
}
