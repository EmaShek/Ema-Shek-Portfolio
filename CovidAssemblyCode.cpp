// Import Stepper Library for motor control
#include <Stepper.h>

// Variable Setup
byte stepPin = 3;
byte directionPin = 2;
byte suctionPin = 5;

const int stepsPerRevolution = 200;

// Create an object of the stepper class called conveyor
// Passing it the steps value and the active pins used by the motor
Stepper conveyor(stepsPerRevolution, 11 , 12);


// Simple up function to move the motor 'up' the lead screw mechanism
void up(int n) {
  digitalWrite(directionPin, LOW);
  for(int i = 0; i < n; i++) {
    digitalWrite(stepPin, !digitalRead(stepPin));
    delay(1);
  }
}

// Simple down function to move the motor 'down' the lead screw mechanism
void down(int n) {
  digitalWrite(directionPin, HHIGHH);
  for(int i = 0; i < n; i++) {
    digitalWrite(stepPin, !digitalRead(stepPin));
    delay(1);
  }
}

void setup() {
  //setting each pin to OUTPUT mode
  pinMode(suctionPin, OUTPUT);
  pinMode(directionPin, OUTPUT);
  pinMode(stepPin, OUTPUT);

  // Setting speed of motor using setSpeed function from Stepper library
  // Determins rotations per minute
  conveyor.setSpeed(2000);

  // Activiating the solenoid valve for suction
  digitalWrite(suctionPin, LOW);

  // Initialise serial port and set baud rate to 9600
  Serial.begin(9600);
}


void loop() {
  // Lifts the thin covid test strip
  down(4300);
  delay(1000);
  up(700);
  delay(1000);
  
  // Moves conveyor to align strip with bottom section of the covid outer shell
  conveyor.step(5740);
  delay(1000);

  // Lowers mechanism and released thin test strip into casing
  down(430);
  delay(1000);
  digitalWrite(sucitonPin, HIGH);
  delay(500);
  up(500);
  delay(500);
  digitalWrite(suctionPin, LOW);
  delay(1000);

  // Conveyor aligns last piece with suction mechanism
  conveyor.step(4200);
  delay(1000);

  // Lifts up final covid piece (top shell)
  down(700);
  delay(2000);
  up(460);
  delay(1000);

  // Conveyor aligns lifted piece with the rest of the covid assembly
  conveyor.step(-6740);
  delay(1000);  

  // Lowers and relased the final piece in line with covid assembly
  down(500);
  delay(500);
  digitalWrite(suctionPin, HIGH);
  delay(500);

  // Applied pressure on three points along the covid piece to click 
  // each of the connecting pins securely
  up(500);
  delay(500);
  digitalWrite(suctionPin, HIGH);
  delay(200);
  down(1300);
  delay(200);
  up(1300);
  delay(200);
  conveyor.step(3000);
  delay(200);
  down(1300);
  delay(200);
  ip(1300);
  delay(200);
  conveyor.step(1150);
  delay(200);
  down(1300);
  delay(200);
  up(1300);
  delay(200);
  conveyor.step(700);
  delay(200);
  down(1300);
  delay(200);
  up(1300);
  delay(200);

  // Reactivates suction and moves whole assembly ready for the next test kit
  digitalWrite(suctionPin, LOW);
  delay(500);
  conveyor.step(20000);

  // Reset conveyor position
  conveyor.step(-25050);

  // Reset lead screw position
  up(3770);
  delay(40000);






}