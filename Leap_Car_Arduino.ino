#define m1_1 3
#define m1_2 4
#define m2_1 5
#define m2_2 6


void motors(){
pinMode(m1_1,OUTPUT);
pinMode(m1_2,OUTPUT);
pinMode(m2_1,OUTPUT);
pinMode(m2_2,OUTPUT);

}
void forward(){
digitalWrite(m1_1,HIGH);
digitalWrite(m1_2,LOW);
digitalWrite(m2_1,HIGH);
digitalWrite(m2_2,LOW);

}

void backward(){

digitalWrite(m1_1,LOW);
digitalWrite(m1_2,HIGH);
digitalWrite(m2_1,LOW);
digitalWrite(m2_2,HIGH);

}

void stop(){
digitalWrite(m1_1,LOW);
digitalWrite(m1_2,LOW);
digitalWrite(m2_1,LOW);
digitalWrite(m2_2,LOW);

}
void right(){
  digitalWrite(m1_1,LOW);
digitalWrite(m1_2,HIGH);
digitalWrite(m2_1,HIGH);
digitalWrite(m2_2,LOW);

  }

  void left(){
  digitalWrite(m1_1,HIGH);
digitalWrite(m1_2,LOW);
digitalWrite(m2_1,LOW);
digitalWrite(m2_2,HIGH);
  

}

void setup(){
motors();
backward();
Serial.begin(9600);
}


void loop(){

if(Serial.available()){
  char val=Serial.read();
  if(val=='F') forward();
  else if(val=='B') backward();
  else if(val=='R') right();
  else if(val=='L') left();
  else stop();
  
}
}






