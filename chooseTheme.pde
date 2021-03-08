void chooseTheme(){
  
  Group g1 = cp5.addGroup("theme")
                .setBackgroundColor(color(155, 155, 155))
                .setColorForeground(foreground)
                .setColorBackground(background)
                .setBackgroundHeight(100)
                .setHeight(15)
                .open()
                .setTitle("                                                                                                                                                        Choose a theme").setFont(font_small)
                ;
  
  radio = cp5.addRadioButton("radio")
     .setSize(40,20)
     .setColorForeground(foreground)
     .setColorActive(active)
     .setColorBackground(background)
     .setColorLabel(color(255))
     .setItemsPerRow(5)
     .setSpacingColumn(50)
     .setPosition(250, 25)
     .setItemWidth(50)
     .setItemHeight(50)
     .setLabelPadding(-35, 50) 
     .addItem("black", 0)
     .addItem("red", 1)
     .addItem("green", 2)
     .addItem("blue", 3)
     .addItem("grey", 4)
     .activate(3)
     .moveTo(g1)
     ;
     
  accordion = cp5.addAccordion("acc")
                 .setPosition(0,50)
                 .setWidth(1000)
                 .addItem(g1)
                 ;
                 
  accordion.close();
}
  

void radio(int val) {
  
  switch(val) {
    case(1):
      foreground = r_foreground;
      background = r_background;
      active = r_active;
      break;
    case(2):
      foreground = g_foreground;
      background = g_background;
      active = g_active;
      break;
    case(3):
      foreground = b_foreground;
      background = b_background;
      active = b_active;
      break;
    
  }
  
} 
