

int led=11;
int con=1;
int time;
void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
  
  
  if (con%2==0){
    time=500;
    Serial.println("if");
  }
  else if (con%3==0){
    time=250;
    
    Serial.println("else if");
  }
  else{
    time=250;
    Serial.println("else ");
  }
 for(int shame=1; shame<=3; shame++){

  analogWrite(led,20);
  Serial.println("on");
  delay(time);
  digitalWrite(led,LOW);
  Serial.println("off");
  delay(time);


  } 
  delay(750);
  con++;


  
  
  // put your main code here, to run repeatedly:

}
