#define button_pin 2
#define led_pin 11

void setup() {

  Serial.begin(9600);
  pinMode(11,OUTPUT);
  pinMode(button_pin, INPUT);
}

void loop() {
  Serial.println(digitalRead(button_pin));
  
  if (digitalRead(button_pin)==1){
    digitalWrite(led_pin,HIGH);
  }
  else{
    digitalWrite(led_pin,LOW);
  }
  delay(0);
}