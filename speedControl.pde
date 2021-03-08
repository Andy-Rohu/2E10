void speedControl(){
  speedControl = cp5.addKnob("speedValue")
     .setRange(0,255)
     .setValue(255)
     .setPosition(400,750)
     .setRadius(100)
     .setNumberOfTickMarks(1)
     .setTickMarkLength(8)
     .snapToTickMarks(false)
     .setColorForeground(foreground)
     .setColorBackground(background)
     .setColorActive(active)
     .setDragDirection(Knob.HORIZONTAL)
     .setCaptionLabel("").setFont(font);
}

void speedValue(int speedValue){
  speed = speedValue;
  println("Motor Speed: " + speed);
}
