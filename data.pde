void data(){
  data1 = cp5.addChart("Velocity")
               .setPosition(200, 200)
               .setSize(600, 400)
               .setRange(-20, 20)
               .setView(Chart.BAR_CENTERED)
               .setStrokeWeight(5)
               .setColorCaptionLabel(250)
               .setColorBackground(background)
               ;

  data2 = cp5.addChart("Path")
               .setPosition(200, 200)
               .setSize(600, 400)
               .setRange(-20, 20)
               .setView(Chart.BAR_CENTERED)
               .setStrokeWeight(5)
               .setColorCaptionLabel(250)
               .setColorBackground(background)
               ;
               
  data1.addDataSet("incoming");
  data1.setData("incoming", new float[100]);
  
  data2.addDataSet("incoming");
  data2.setData("incoming", new float[100]);
  
  chartTab = cp5.addButtonBar("chartTab")
                .setPosition(200, 175)
                .setSize(600, 25)
                .addItems(split("a b"," "))
                .setColorForeground(foreground)
                .setColorBackground(background)
                .setColorActive(active)
                .setCaptionLabel("Speed Value").setFont(font_small)
                .setValue(0)
                .update();
                chartTab.changeItem("a","text","Velocity");
                chartTab.changeItem("b","text","Path");
}

void chartTab(int click) {
  
  if(click == 0){
    data2.hide();
    data1.show();
  }
  
  if(click == 1){
    data1.hide();
    data2.show();
  }
  
}
