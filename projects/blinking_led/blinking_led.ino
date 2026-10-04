
#define redled 11
#define yellowled 10
#define greenled 9
#define button 2
#define led_size 3
#define ptmeter A2

byte led_array[led_size]={
  redled,yellowled,greenled
};
int redledstate=LOW;
int greenledstate=LOW;
unsigned long timeredbegin=millis();
unsigned long timebuttonbegin=millis();
int buttonstate=LOW;
 byte ledtogglestate=LOW;
volatile bool istrue=false;

void buttoninterrupts(){
  unsigned long timebuttonend=millis();
  if ((timebuttonend-timebuttonbegin)>50){
  istrue=true;
  timebuttonend=timebuttonbegin;}
}


void setup() {
  for (int i=0;i<led_size;i++){
    pinMode(led_array[i],OUTPUT);
  }
  pinMode(button,INPUT);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(button),
                  buttoninterrupts,
                  FALLING);
  // put your setup code here, to run once:

}
int deay;
void loop() {
  

  unsigned long timeend=millis();
  int elapsed=timeend-timeredbegin;
   if (Serial.available()>0){
    deay=Serial.parseInt();
    Serial.println(deay);
   
  }
  if ((deay>100)&&(deay<1000)){
    if (elapsed>deay){




      if (redledstate==LOW){
        redledstate=HIGH;

      }
      else{
        redledstate=LOW;
      }
      digitalWrite(redled,redledstate);
      timeredbegin+=deay;
    }
  // put your main code here, to run repeatedly:
  
  }
  if(istrue){

  int reading = digitalRead(button);

  if (reading != buttonstate) {

    buttonstate = reading;

    if (buttonstate == HIGH) {

      if (greenledstate == LOW) {
        greenledstate = HIGH;
      }
      else {
        greenledstate = LOW;
      }

      digitalWrite(greenled, greenledstate);
    }
  }

  timebuttonbegin = timeend;
  }

  
  
  float brightness=analogRead(A2)/4;
  analogWrite(yellowled,brightness);
  Serial.println(digitalRead(button));

  
}
