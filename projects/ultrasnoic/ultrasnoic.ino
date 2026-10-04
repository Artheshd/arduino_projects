#include <LiquidCrystal_I2C.h>
#include <wire.h>


#define echoPin 3
#define triggerPin 4
#define greenLed 9
#define yellowLed 10
#define redLed 6

volatile unsigned long t1;
volatile unsigned long t2;
volatile bool echoCheck=false;
unsigned long timeUltrasonic = millis();
int elay=50;

double ultrasonicecho(){

  double duration=t2 - t1; //in microseconds
  double distance=duration/58.0;
  return distance;
}

void pulsecheck(){
  if (digitalRead(echoPin)==HIGH){
    t1=micros();
  }
  else{
    t2=micros();
    echoCheck=true;
  }
}

void ultrasonictrigger(){
  digitalWrite(triggerPin,LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin,LOW); 
}


void setup() {
  Serial.begin(115200);
  pinMode(echoPin,INPUT);
  pinMode(triggerPin,OUTPUT);
  pinMode(redLed,OUTPUT);
  pinMode(yellowLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(echoPin),pulsecheck,CHANGE);

  // put your setup code here, to run once:

}

void loop() {
  unsigned long timeNow=millis();
  if ((timeNow-timeUltrasonic)>elay){
    ultrasonictrigger();
    timeUltrasonic=timeNow;
    Serial.println(ultrasonicecho());
  }
  if(echoCheck){
    echoCheck=false;
  //if ((timeNow-timeUltrasonic)>elay){
  //}
  if (ultrasonicecho()>100){
    digitalWrite(greenLed,HIGH);
    digitalWrite(redLed,LOW);
    digitalWrite(yellowLed,LOW);
  }
  else if((ultrasonicecho()<=100) && (ultrasonicecho()>=20)){
    digitalWrite(greenLed,LOW);
    digitalWrite(redLed,LOW);
    digitalWrite(yellowLed,HIGH);
  }
  else{
    digitalWrite(greenLed,LOW);
    digitalWrite(redLed,HIGH);
    digitalWrite(yellowLed,LOW);
  }
  }
  // put your main code here, to run repeatedly:

}
