#define button_pin 2
#define led_pin 11

void setup() {
  Serial.begin(9600);
  pinMode(button_pin,INPUT);
  pinMode(led_pin,OUTPUT);
  // put your setup code here, to run once:

}


void loop() {
  
  Serial.println(digitalRead(button_pin));
  delay(500);
  
  

  // put your main code here, to run repeatedly:

}
