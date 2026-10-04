#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <IRremote.h>

#define redled 6
#define yellowled 10
#define greenled 9
#define echopin 3
#define triggerpin 4
#define irpin 5
#define buttonpin 2
double distance_cm;
unsigned long tbegin=millis();
volatile unsigned long t1;
volatile unsigned long t2;
volatile bool isecho=false;
bool isinch=false;
bool is=false;
unsigned long yellowtime=millis();
unsigned long yellowtime2=millis();
unsigned long buttontime=millis();
byte buttonstate=LOW;

bool danger=false;

LiquidCrystal_I2C lcd(0x27,16,2);

void buttonfunc(){
  if (millis()-buttontime>50){
  if (buttonstate!=digitalRead(buttonpin)){
    if (digitalRead(buttonpin)==1){
      buttonstate=digitalRead(buttonpin);
    }
    else{
      buttonstate=digitalRead(buttonpin)
      danger=false;
    }
  }
  buttontime=millis();
  }
}

void distancestate(){
 int  blinktime=distance_cm*4;
  if (distance_cm>=10){
    if ((millis()-yellowtime)>blinktime){
      digitalWrite(yellowled,!digitalRead(yellowled));
      yellowtime=millis();

    }
    digitalWrite(greenled,LOW);
    lcd.setCursor(0, 1);
    lcd.print("detecting");


  }
  else{
    if  ((millis()-yellowtime2)>1000){
      digitalWrite(yellowled,!digitalRead(yellowled));
      digitalWrite(greenled,!digitalRead(greenled));
      yellowtime2=millis();
      danger=true;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("OBSTRUCTION!!!");
  }
  }
}



void defaultstate(){
  isinch=false;
}

void switchinch(){
  if (isecho){
    isecho=false;
      if (is){
        if(isinch){
          isinch=false;
          echo();
        }
        else{
          isinch=true;
          echo();
        }
        is=false;
      }
  else{
    echo();
  }
    }
}

void trigger(){
  digitalWrite(triggerpin,LOW);
  delayMicroseconds(2);
  digitalWrite(triggerpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerpin,LOW);

}

void echo(){
  double duration=t2-t1;

  distance_cm=duration/58.0;
  double distance_inches=duration/(58.0*2.54);
  if (isinch==false){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("distance:");
    lcd.print(distance_cm);
    lcd.print("cm");

  }
  else{
        lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("distance:");
    lcd.print(distance_inches);
    lcd.print("in");
  }
  

}

void smallecho(){
  if (digitalRead(echopin)==HIGH){
    t1=micros();
  }
  else{
    t2=micros();
    isecho=true;
}
}

void setup() {
  Serial.begin(115200);
  IrReceiver.begin(irpin);
  pinMode(triggerpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(yellowled,OUTPUT);
  pinMode(greenled,OUTPUT);
  pinMode(buttonpin,INPUT);
  lcd.init();
  lcd.backlight();
  attachInterrupt(digitalPinToInterrupt(echopin),smallecho,CHANGE);

}

void loop() {

if (IrReceiver.decode()){
  int input= IrReceiver.decodedIRData.command;
  switch(input){
    case 1:
    is=true;
    break;
    case 92:
    danger=false;
    break;

    

  }
}
  IrReceiver.resume();  
  if(danger){}
  else{
  if (millis()-tbegin>60){

    trigger();
    switchinch();
    tbegin=millis();
  }
  }
  distancestate();
  Serial.println(distance_cm);
  buttonfunc();
}
