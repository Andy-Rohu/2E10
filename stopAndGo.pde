void stopAndGo(){
  PImage stopandgo[] = {loadImage("GO.png"), loadImage("GO_Active.png"), loadImage("STOP.png"), loadImage("STOP_Active.png")};
  stopandgo[0].resize(125,125);
  stopandgo[1].resize(125,125);
  stopandgo[2].resize(125,125);
  stopandgo[3].resize(125,125);
  GO = cp5.addRadioButton("GO")
     .setPosition(225,700)
     .setValue(0)     
     .setImages(stopandgo[0], stopandgo[1], stopandgo[1])
     .addItem("go", 0)
     ;
     
  STOP = cp5.addRadioButton("STOP")
     .setPosition(650,700)
     .setValue(0)     
     .setImages(stopandgo[2], stopandgo[3], stopandgo[3])
     .addItem("stop", 0)
     ;
     
}

void GO(int value){
  if(value == 0){
    STOP.deactivateAll();
    myClient.write('g');
  }  
}

void STOP(int value){
  if(value == 0){
    GO.deactivateAll();
    myClient.write('s');
  }
}
     
