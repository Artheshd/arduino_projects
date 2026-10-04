#define led_pin 11
#define pm_pin A2
void setup() {
  Serial.begin(9600);
  pinMode(led_pin,OUTPUT);
  
  

  // put your setup code here, to run once:

}

void loop() {
  Serial.println(analogRead(pm_pin));
  float signal=analogRead(pm_pin)/4;
  analogWrite(led_pin,signal);
  delay(100);
  // put your main code here, to run repeatedly:

}
