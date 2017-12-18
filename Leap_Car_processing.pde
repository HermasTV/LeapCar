import com.leapmotion.leap.*;

import processing.serial.*;

Serial myPort;
Controller leap;
void setup() {

  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
  leap=new Controller();
  size(200, 200);
}

void draw() {
  background(100);
  fill(255);
  HandList hands = leap.frame().hands();
  Hand hand = hands.get(0);
  float pitch = hand.direction().pitch()*100;
  float yaw = hand.direction().yaw()*100;
  float roll = hand.palmNormal().roll()*100;

  if (pitch<-50) {
    myPort.write('F');
  } else if (pitch>40 && pitch < 300) {
    myPort.write('B');
  } else if (yaw<-80) {
    myPort.write('L');
  } else if (yaw>50 && yaw< 300) {
    myPort.write('R');
  } else {
    myPort.write('S');
  }
  text(pitch+" pitch ", 50, 50);
  text(yaw+" yaw ", 50, 80);
  text(roll+" roll ", 50, 120);
}