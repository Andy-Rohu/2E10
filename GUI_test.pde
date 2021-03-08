import controlP5.*;
import processing.net.*;

ControlP5 cp5;
Client myClient;

ButtonBar bar, chartTab;
Knob speedControl;
Accordion accordion;
RadioButton radio, GO, STOP;
Chart data1, data2;

int speed;
PFont font, font_small, font_input;
String input;

color g_foreground = color (100, 200, 50);
color g_background = color (50, 80, 20);
color g_active = color (100, 200, 50);

color b_foreground = color (50, 100, 200);
color b_background = color (20, 50, 80);
color b_active = color (50, 100, 200);

color r_foreground = color (250, 70, 70);
color r_background = color (150, 0, 0);
color r_active = color (250, 70, 70);

color foreground = b_foreground;
color background = b_background;
color active = b_active;


void setup(){
  size(1000, 1000);
  smooth();
  noStroke();
  
  font = createFont("Nirmala.ttf", 32, true);
  font_small = createFont("Roboto-Regular.ttf", 12, true);
  font_input = createFont("digital-7.ttf", 30, true);
  
  cp5 = new ControlP5(this);
  myClient = new Client(this, "192.168.0.157", 5200);
  
  driveMethod();
  speedControl();
  chooseTheme();
  data();
  stopAndGo();
  
  fill(background);
  rect(200, 600, 600, 50);
  fill(255);
  textFont(font_input);
  textAlign(CENTER);
  text("Arduino Telemetry", 500, 635);
   
}

void draw(){
  data1.push("incoming", (sin(frameCount*0.1)*10));
  data2.push("incoming", (tan(frameCount*0.1)*10));
  
  if(myClient.available() > 0){
    fill(background);
    rect(200, 600, 600, 50);
    input = myClient.readString();
    println(input);
  }
  else{
    input = "";
  }
  fill(250);
  textFont(font_input);
  textAlign(CENTER);
  text(input, 500, 635);
  
  
  
  radio.setColorForeground(foreground);
  radio.setColorBackground(background);
  radio.setColorActive(active);
  
  speedControl.setColorForeground(foreground);
  speedControl.setColorBackground(background);
  speedControl.setColorActive(active);
  
  bar.setColorForeground(foreground);
  bar.setColorBackground(background);
  bar.setColorActive(active);
  
  data1.setColorForeground(foreground);
  data1.setColorBackground(background);
  data1.setColorActive(active);
  
  data2.setColorForeground(foreground);
  data2.setColorBackground(background);
  data2.setColorActive(active);
  
}
