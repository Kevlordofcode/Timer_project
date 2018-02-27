//Timer simple.ino
#include <Arduino.h>

int temps(4000);
float tempsrestant;

#define Start 12
#define Buzz 8
#define Relais_1_agrand 5



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode (Start, INPUT_PULLUP);
pinMode (Buzz, OUTPUT);
pinMode (Relais_1_agrand, OUTPUT);

Serial.print(temps);
digitalWrite(Buzz, HIGH);
delay(500);
digitalWrite(Buzz, LOW);

}

bip(int lb) {
	digitalWrite(Buzz, HIGH);
	delay(lb);
	digitalWrite(Buzz, LOW);
	return 0;
}

void loop() {
  // put your main code here, to run repeatedly:

if (digitalRead(Start) == LOW) {
	unsigned long endtime = millis() + temps;
	while (millis() < (endtime)) {
	tempsrestant = (((float)endtime - (float)millis())/1000);
	Serial.print(tempsrestant, 1);
	Serial.println();	
	delay(300);
	}
	digitalWrite(Relais_1_agrand, LOW);
	bip(200);
	delay(500);
	}

}