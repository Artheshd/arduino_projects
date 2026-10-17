// ========================================
// DRIVER 1 = RIGHT WHEELS
// ========================================

#define R_ENA 5
#define R_IN1 2
#define R_IN2 4

#define R_ENB 6
#define R_IN3 7
#define R_IN4 8


// ========================================
// DRIVER 2 = LEFT WHEELS
// ========================================

#define L_ENA 9
#define L_IN1 12
#define L_IN2 13

#define L_ENB 10
#define L_IN3 A0
#define L_IN4 A1


int speedValue = 255;


// ========================================

void setup() {

  pinMode(R_ENA, OUTPUT);
  pinMode(R_IN1, OUTPUT);
  pinMode(R_IN2, OUTPUT);
  pinMode(R_ENB, OUTPUT);
  pinMode(R_IN3, OUTPUT);
  pinMode(R_IN4, OUTPUT);

  pinMode(L_ENA, OUTPUT);
  pinMode(L_IN1, OUTPUT);
  pinMode(L_IN2, OUTPUT);
  pinMode(L_ENB, OUTPUT);
  pinMode(L_IN3, OUTPUT);
  pinMode(L_IN4, OUTPUT);

  Serial.begin(9600);

  stopCar();
}


// ========================================
// LOOP
// ========================================

void loop() {

  if (Serial.available()) {

    char command = Serial.read();

    if (command == 'F' || command == 'f')
      forward();

    else if (command == 'B' || command == 'b')
      backward();

    else if (command == 'L' || command == 'l')
      left();

    else if (command == 'R' || command == 'r')
      right();

    else if (command == 'S' || command == 's')
      stopCar();
  }
}


// ========================================
// FORWARD
// ========================================

void forward() {

  // RIGHT SIDE FORWARD
  digitalWrite(R_IN1, HIGH);
  digitalWrite(R_IN2, LOW);

  digitalWrite(R_IN3, HIGH);
  digitalWrite(R_IN4, LOW);


  // LEFT SIDE REVERSED
  digitalWrite(L_IN1, LOW);
  digitalWrite(L_IN2, HIGH);

  digitalWrite(L_IN3, LOW);
  digitalWrite(L_IN4, HIGH);

  setSpeed();
}


// ========================================
// BACKWARD
// ========================================

void backward() {

  // RIGHT SIDE BACKWARD
  digitalWrite(R_IN1, LOW);
  digitalWrite(R_IN2, HIGH);

  digitalWrite(R_IN3, LOW);
  digitalWrite(R_IN4, HIGH);


  // LEFT SIDE REVERSED
  digitalWrite(L_IN1, HIGH);
  digitalWrite(L_IN2, LOW);

  digitalWrite(L_IN3, HIGH);
  digitalWrite(L_IN4, LOW);

  setSpeed();
}


// ========================================
// LEFT
// ========================================

void left() {

  // RIGHT SIDE BACKWARD
  digitalWrite(R_IN1, LOW);
  digitalWrite(R_IN2, HIGH);

  digitalWrite(R_IN3, LOW);
  digitalWrite(R_IN4, HIGH);


  // LEFT SIDE BACKWARD
  digitalWrite(L_IN1, LOW);
  digitalWrite(L_IN2, HIGH);

  digitalWrite(L_IN3, LOW);
  digitalWrite(L_IN4, HIGH);

  setSpeed();
}


// ========================================
// RIGHT
// ========================================

void right() {

  // RIGHT SIDE FORWARD
  digitalWrite(R_IN1, HIGH);
  digitalWrite(R_IN2, LOW);

  digitalWrite(R_IN3, HIGH);
  digitalWrite(R_IN4, LOW);


  // LEFT SIDE FORWARD
  digitalWrite(L_IN1, HIGH);
  digitalWrite(L_IN2, LOW);

  digitalWrite(L_IN3, HIGH);
  digitalWrite(L_IN4, LOW);

  setSpeed();
}


// ========================================
// STOP
// ========================================

void stopCar() {

  digitalWrite(R_IN1, LOW);
  digitalWrite(R_IN2, LOW);
  digitalWrite(R_IN3, LOW);
  digitalWrite(R_IN4, LOW);

  digitalWrite(L_IN1, LOW);
  digitalWrite(L_IN2, LOW);
  digitalWrite(L_IN3, LOW);
  digitalWrite(L_IN4, LOW);

  analogWrite(R_ENA, 0);
  analogWrite(R_ENB, 0);

  analogWrite(L_ENA, 0);
  analogWrite(L_ENB, 0);
}


// ========================================
// SPEED
// ========================================

void setSpeed() {

  analogWrite(R_ENA, speedValue);
  analogWrite(R_ENB, speedValue);

  analogWrite(L_ENA, speedValue);
  analogWrite(L_ENB, speedValue);
}