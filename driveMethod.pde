void driveMethod(){
  
  bar = cp5.addButtonBar("bar")
     .setPosition(0, 0)
     .setSize(1000, 50)
     .addItems(split("a b"," "))
     .setColorForeground(foreground)
     .setColorBackground(background)
     .setColorActive(active)
     .setCaptionLabel("Speed Value").setFont(font);
     bar.changeItem("a","text","Line Following");
     bar.changeItem("b","text","Free Control");
     
}

void bar(int click) {
  
  if(click == 0){
    speedControl.show();
  }
  
  if(click == 1){
    speedControl.hide();
  }
  
}
