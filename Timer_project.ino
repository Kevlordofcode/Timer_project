//Timer simple.ino
#include <Arduino.h>

int ExpTime(4000);
int Step(2);
int temps;
float tempsaffiche;
float tempsrestant;

#define Start 12
#define StepUp 11
#define StepDn 10
#define Buzz 8
#define Relais_1_agrand 5
#define Relais_2_inact 4

	//fonction bip
void bip(int lb) {
	digitalWrite(Buzz, HIGH);
	delay(lb);
	digitalWrite(Buzz, LOW);
}

	//Fonction compte à rebours
void countdown(int temps){
	unsigned long endtime = millis() + temps;
	while (millis() < (endtime)) {
		tempsrestant = (((float)endtime - (float)millis())/1000);
		Serial.print(tempsrestant, 1);
		Serial.println();	
		delay(300);
	}


}

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode (Start, INPUT_PULLUP);
pinMode (Buzz, OUTPUT);
pinMode (Relais_1_agrand, OUTPUT);
pinMode (Relais_2_inact, OUTPUT);

	//Son pour dire que c'est initialisé
Serial.print(temps);
digitalWrite(Buzz, HIGH);
delay(500);
digitalWrite(Buzz, LOW);

}



void loop() {
  // put your main code here, to run repeatedly:

  //Step up exposition
if(digitalRead(StepUp) == LOW) {
	ExpTime = ExpTime + Step;
	tempsaffiche = ExpTime/1000;
	Serial.print(tempsaffiche, 1);
}

  //Step down exposition


  //Déclenche exposition
if (digitalRead(Start) == LOW) {
	digitalWrite(Relais_2_inact, LOW);
	digitalWrite(Relais_1_agrand, HIGH);
	countdown(ExpTime);
	}
	digitalWrite(Relais_1_agrand, LOW);
	digitalWrite(Relais_2_inact, HIGH);
	bip(200);								//A supprimer pour version définitive
	delay(500);								//A supprimer pour version définitive
	

}