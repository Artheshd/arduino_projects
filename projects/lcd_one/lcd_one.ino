#include <LiquidCrystal_I2C.h>
#include <wire.h>

#define triggerpin 4
#define echopin 3
volatile unsigned long t1;
volatile unsigned long t2;
unsigned long tfunc=millis();
unsigned long  tbegin=millis();
volatile bool done=false;

LiquidCrystal_I2C lcd(0x27,16,2);


void triggermode(){
  digitalWrite(triggerpin,LOW);
  delayMicroseconds(2); 
  digitalWrite(triggerpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerpin,LOW);

}

void echoo(){
 
  if (digitalRead(echopin)==HIGH){
     t1=micros();
  }
  else{
     t2=micros();
    done=true;
  }

}

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,1);
  pinMode(triggerpin,OUTPUT);
  pinMode(echopin,INPUT);
  attachInterrupt(digitalPinToInterrupt(echopin),echoo,CHANGE);


 

  // put your setup code here, to run once:

}

void echo(){
  if (millis()-tfunc>5000){
  lcd.clear();

  double duration=t2-t1;
  double distance=duration/58.0;
  Serial.println(duration);
  Serial.println(distance);
  Serial.println("----");
  lcd.setCursor(0,0);
  lcd.print(duration);
  lcd.setCursor(0,1);
  lcd.print(distance);
  }
}

void loop() {
  unsigned long  tend=millis();
  if (tend-tbegin>50){

  triggermode();
 
  tbegin=tend;
  }
  if (done){
  done=false;
  echo();
  }
}
