#include <IRremote.h>

#define IRpin 5
#define redled 6
#define yellowled 10
#define greenled 9
#define IRbutton0 0
#define IRbutton1 1
#define IRbutton2 2
#define IRbutton3 3
#define IRbutton4 4
#define IRbutton5 5
#define IRbuttonSelect 92
#define inc 32
#define dec 33
unsigned long t1= millis();

int i=255;
int on=-1;


void alloff(){
  digitalWrite(redled,LOW);
  digitalWrite(yellowled,LOW);
  digitalWrite(greenled,LOW);

  
}

void button1(int led){
  alloff();
  
  analogWrite(led,i);
  on=led;
}

void brigthen(int brightness){
  if (on == -1) {
  return;
}
  
  if (brightness==inc && i<255){

    i=min(i+20,255);
  }
  if (brightness==dec && i>=2){

    i=max(i-20,0);
  }
  analogWrite(on, i);
  Serial.println(i);

}


void setup() {
  Serial.begin(115200);
  IrReceiver.begin(IRpin);
  pinMode(greenled,OUTPUT);
  pinMode(redled,OUTPUT);
  pinMode(yellowled,OUTPUT);
 

  Serial.println("IR Receiver Ready");
}

bool blinking=false;

void loop() {
  
  unsigned long t2= millis();

 
  if(IrReceiver.decode()){
    
    blinking=false;
    int input=IrReceiver.decodedIRData.command;
    Serial.println(input);
    switch (input){

      case IRbuttonSelect:
      alloff();
      
      break;

      case IRbutton1:
      button1(redled);
      break;

      case IRbutton2:
      button1(yellowled);
      break;

      case IRbutton3:
      button1(greenled);
      break;

      case IRbutton4:
      on=-1;
      blinking=true;
      alloff();
      break;

      case inc :
        brigthen(inc);
        break;
      case dec:
        brigthen(dec);
        break;

      
      
      
    }
    IrReceiver.resume();
    //Serial.println(IrReceiver.decodedIRData.decodedRawData,HEX); 
   
  }

  if (blinking && millis()-t1>100 ){
    

    digitalWrite(yellowled, !digitalRead(yellowled));
    digitalWrite(redled, !digitalRead(redled));
    digitalWrite(greenled, !digitalRead(greenled));
    t1=millis();
  }
}