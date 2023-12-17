#include <SoftwareSerial.h>
SoftwareSerial HM10(0, 1); 

void setup() {
  Serial.begin(9600);
  HM10.begin(9600);
  #define Mleft_dir 2  //defines the direction of left motors
  #define Mleft 5   //defines the speed of left motors
  #define Mright_dir 4   //defines the direction of right motors
  #define Mright 9   //defines the speed of right motors
}

void loop() {
    //keyboard control function runs on loops to hear commands on direction and speed of rover
    keyboardControl();
}

 //move forward
  void front(int ms)
  {
    digitalWrite(Mleft_dir,HIGH);
    analogWrite(Mleft,200);
    digitalWrite(Mright_dir,LOW);
    analogWrite(Mright,200);
    delay(ms);
  }
  
  //move backward
  void back(int ms)
  {
    digitalWrite(Mleft_dir,LOW);
    analogWrite(Mleft,200);
    digitalWrite(Mright_dir,HIGH);
    analogWrite(Mright,200);
    delay(ms);
  }
  
  //move left
  void left(int ms)
  {
    digitalWrite(Mleft_dir,HIGH);
    analogWrite(Mleft,200);
    digitalWrite(Mright_dir,HIGH);
    analogWrite(Mright,200);
    delay(ms);
  }
  
  //move right
  void right(int ms)
  {
    digitalWrite(Mleft_dir,LOW);
    analogWrite(Mleft,200);
    digitalWrite(Mright_dir,LOW);
    analogWrite(Mright,200);
    delay(ms);
  }
  
  //brake
  void brake(int ms)
  {
    analogWrite(Mleft,0);
    analogWrite(Mright,0);
    delay(ms);
  }

//control robot via computer keyboard & bluetooth module
//Must be paired to bluetooth module HC-06 on host computer!
//You can utilize any bluetooth applications to connect to HC-06 module and pass it chars
//w: forward
//a: left
//s: reverse
//d: right
//0: stop

void keyboardControl(){
    HM10.listen();  // listen the HM10 port
    while (HM10.available() > 0) {   // if HM10 sends data then read
    char data = HM10.read();
    char indata = char(data); 
    Serial.println(data);
    switch (data) { // Switch-case of the signals in the serial port 
    case 'a' : //left 
    Serial.println("left");
    left(700); 
    break;
    case 's' : //reverse
    Serial.println("backward");
    back(2000); 
    break;
    case 'd' : // right
    Serial.println("right"); 
    right(700); 
    break;
    case 'w': // forward
    Serial.println("forward"); 
    front(2000);
    break;
    case '0': // stop case
    Serial.println("stop");
    default : 
    break;
    }
  }
}