#define redled 10
#define yellowled 9
unsigned long redledtime=millis();
unsigned long yellowledtime=millis();
int redledstate=LOW;
void setup() {
  pinMode(redled,OUTPUT);
  pinMode(yellowled,OUTPUT);
  Serial.begin(115200);
  
  
  // put your setup code here, to run once:

}



void loop() {
  
 unsigned long timeend=millis();
 Serial.println(timeend-redledtime);
  if ((timeend-redledtime)>300){
    if (redledstate==LOW){
      redledstate=HIGH;
    
    }
    else{
      redledstate=LOW;
    }
    digitalWrite(redled,redledstate);
    redledtime+=300;

 
  }
  



  

  // put your main code here, to run repeatedly:

}
