#include <SoftwareSerial.h>
SoftwareSerial SIM900(2, 3);
String textForSMS;

int pirsensor = 10;
int buzzer = 9;
int red = 7;
int green = 8;

void setup() {
  randomSeed(analogRead(0));
  Serial.begin(9600);
  SIM900.begin(9600); // original 19200. while enter 9600 for sim900A
  Serial.println(" logging time completed!");
  pinMode(pirsensor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  digitalWrite(buzzer, LOW);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);

  delay(100);

}

void loop() {


  if ( digitalRead(pirsensor) == HIGH) //
  {
    textForSMS =  "\Any Person in your Room  Plz Check It ";

    digitalWrite(buzzer, HIGH);
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    Serial.println(textForSMS);
    Serial.println("message sent.");
    delay(8000);
  }
  if ( digitalRead(pirsensor) == LOW) //
  {
    digitalWrite(buzzer, LOW);
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    delay(1000);
  }

}
