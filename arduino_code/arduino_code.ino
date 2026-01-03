// L298N 1 fata
const int IN1_1 = 22;
const int IN2_1 = 23;
const int IN3_1 = 24;
const int IN4_1 = 25;

// L298N 2 spate
const int IN1_2 = 26;
const int IN2_2 = 27;
const int IN3_2 = 28;
const int IN4_2 = 29;

const int ENA1 = 2;
const int ENB1 = 3;
const int ENA2 = 4;
const int ENB2 = 5;

int viteza = 150;

void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);
  Serial.println("Arduino Mega ready!");
  
  pinMode(IN1_1, OUTPUT);
  pinMode(IN2_1, OUTPUT);
  pinMode(IN3_1, OUTPUT);
  pinMode(IN4_1, OUTPUT);
  pinMode(IN1_2, OUTPUT);
  pinMode(IN2_2, OUTPUT);
  pinMode(IN3_2, OUTPUT);
  pinMode(IN4_2, OUTPUT);
  
  pinMode(ENA1, OUTPUT);
  pinMode(ENB1, OUTPUT);
  pinMode(ENA2, OUTPUT);
  pinMode(ENB2, OUTPUT);
  
  analogWrite(ENA1, viteza);
  analogWrite(ENB1, viteza);
  analogWrite(ENA2, viteza);
  analogWrite(ENB2, viteza);
  
  stopMotors();
}

void loop() {
  if (Serial1.available()) {
    char comanda = Serial1.read();
    
    if (comanda == '\n' || comanda == '\r' || comanda == ' ') {
      return;  
    }
    
    Serial.print("Comanda primita: ");
    Serial.println(comanda);
    
    switch(comanda) {
      case 'F':
        moveForward();
        Serial.println("-> INAINTE");
        break;
        
      case 'B':
        moveBackward();
        Serial.println("-> INAPOI");
        break;
        
      case 'L':
        moveLeft();
        Serial.println("-> STANGA");
        break;
        
      case 'R':
        moveRight();
        Serial.println("-> DREAPTA");
        break;
        
      case 'S':
        stopMotors();
        Serial.println("-> STOP");
        break;
        
      default:
        Serial.println((int)comanda);
        break;
    }
  }
}

void moveForward() {
  digitalWrite(IN2_1, HIGH);
  digitalWrite(IN1_1, LOW);
  digitalWrite(IN4_1, HIGH);
  digitalWrite(IN3_1, LOW);
  digitalWrite(IN1_2, HIGH);
  digitalWrite(IN2_2, LOW);
  digitalWrite(IN4_2, HIGH);
  digitalWrite(IN3_2, LOW);
}

void moveBackward() {
  digitalWrite(IN2_1, LOW);
  digitalWrite(IN1_1, HIGH);
  digitalWrite(IN4_1, LOW);
  digitalWrite(IN3_1, HIGH);
  digitalWrite(IN1_2, LOW);
  digitalWrite(IN2_2, HIGH);
  digitalWrite(IN4_2, LOW);
  digitalWrite(IN3_2, HIGH);
}

void moveLeft() {
  digitalWrite(IN2_1, HIGH);
  digitalWrite(IN1_1, LOW);
  digitalWrite(IN4_1, LOW);
  digitalWrite(IN3_1, HIGH);
  digitalWrite(IN1_2, LOW);
  digitalWrite(IN2_2, HIGH);
  digitalWrite(IN4_2, HIGH);
  digitalWrite(IN3_2, LOW);
}

void moveRight() {
  digitalWrite(IN2_1, LOW);
  digitalWrite(IN1_1, HIGH);
  digitalWrite(IN4_1, HIGH);
  digitalWrite(IN3_1, LOW);
  digitalWrite(IN1_2, HIGH);
  digitalWrite(IN2_2, LOW);
  digitalWrite(IN4_2, LOW);
  digitalWrite(IN3_2, HIGH);
}

void stopMotors() {
  digitalWrite(IN1_1, LOW);
  digitalWrite(IN2_1, LOW);
  digitalWrite(IN3_1, LOW);
  digitalWrite(IN4_1, LOW);
  digitalWrite(IN1_2, LOW);
  digitalWrite(IN2_2, LOW);
  digitalWrite(IN3_2, LOW);
  digitalWrite(IN4_2, LOW);
}