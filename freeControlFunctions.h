void hardLeft(){
  allStop();
  analogWrite(S1, 255);
  analogWrite(S3, 255);
  delay(500);
  analogWrite(S1, 0);
  analogWrite(S3, 0);
  
}

void hardRight(){
  allStop();
  analogWrite(S2, 255);
  analogWrite(S4, 255);
  delay(500);
  analogWrite(S2, 0);
  analogWrite(S4, 0);
}

void softRight(){
  allStop();
  analogWrite(S4, 255);
  delay(900);
  analogWrite(S4, 0);
}

void softLeft(){
  allStop();
  analogWrite(S1, 255);
  delay(900);
  analogWrite(S1, 0);
}

void forward(){
  allStop();
  analogWrite(S1, speed);
  analogWrite(S4, speed);
  delay(100);
  analogWrite(S1, 0);
  analogWrite(S4, 0);
}

void reverse(){
  allStop();
  analogWrite(S2, speed);
  analogWrite(S3, speed);
  delay(100);
  analogWrite(S2, 0);
  analogWrite(S3, 0);
}

void allStop(){
  analogWrite(S1, 0);
  analogWrite(S2, 0);
  analogWrite(S3, 0);
  analogWrite(S4, 0);
  delay(50);
}

void wait(){
  if(myClient.available()){
    command = myClient.read();
  }
}
