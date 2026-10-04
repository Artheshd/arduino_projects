void setup() {
  pinMode(11,OUTPUT);
  Serial.begin(9600);

}

void loop() {

  for(int i=0;i<=255;i++){
    analogWrite(11,i);
    delay(5);
    Serial.println(i);
  }
  for(int i=255;i>=0;i--){
    analogWrite(11,i);
    delay(5);
    Serial.println(i);
  }
  // put your main code here, to run repeatedly:

}
