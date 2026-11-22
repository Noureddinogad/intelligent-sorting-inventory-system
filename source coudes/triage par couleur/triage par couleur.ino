
#include <Servo.h>

#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6


Servo myServo;

int frequency = 0;
int color = 0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, HIGH);

  myServo.attach(8);

  digitalWrite (S0, HIGH) ;
  digitalWrite (S1, LOW) ;
 
  Serial.begin(9600);

}

void loop() {
 //readColor() 

  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;

  Serial.print("R= ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(500);
  
//GreenColor () 
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;

  Serial.print("G= ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(50);

  //red
  if (R<80 && R >50 && G<250 && G>102 ){
//    myServo.attach(8);
    myServo.write (107);
    delay (500);
//        myServo.detach();

  }
  //green
  else if (R<130 && R>110&& G<164 && G>140){
    myServo.write (145);
//    myServo.detach();
    
  }
  else{ 
//    myServo.attach(8);
    myServo.write(170);
     delay (500);
//         myServo.detach();

  }
  
}


int readColor() {

  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;

  Serial.print("R= ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(500);
}

int GreenColor () {
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;

  Serial.print("G= ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(50);
}
