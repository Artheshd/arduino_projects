#define redled 11
#define yellowled 10
#define greenled 9
#define button 2
#define led_size 3

byte led_array[led_size]={
  redled,yellowled,greenled
}

void setup() {
  for (int i=0;i<led_array;i++){
    pinMode(led_array[i],OUTPUT);
  }
  pinMode(button,INPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
    Serial.println(digitalRead(button));
 
    digitalWrite(redled,HIGH);
    digitalWrite(greenled,HIGH);
    digitalWrite(yellowled,LOW);
    delay(300);

     if (digitalRead(button)==1){
    bool t=true;
    while (t==true){
      digitalWrite(redled,HIGH);
      digitalWrite(greenled,HIGH);
      digitalWrite(yellowled,LOW);
      Serial.println(digitalRead(button));
      if (digitalRead(button)==0){
       t=false;
      }

    }
  }

     digitalWrite(redled,LOW);
    digitalWrite(greenled,LOW);
    digitalWrite(yellowled,HIGH);
    delay(300);

     if (digitalRead(button)==1){
    bool t=true;
    while (t==true){
      digitalWrite(redled,LOW);
      digitalWrite(greenled,LOW);
      digitalWrite(yellowled,HIGH);
      if (digitalRead(button)==0){
         t=false;
      }

    }
  }






  // put your main code here, to run repeatedly:

}
