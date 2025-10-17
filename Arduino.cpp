#include <Servo.h>

int buzzer = 5;
int led = 6;
int echoInput = 3;
int trigOut = 2;
int intervalo = 3000;
int intervalo2 = 6000;
int tempoInit = 0;
int reset = 13;


Servo meuServo;


void setup(){
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(echoInput, INPUT);
  pinMode(trigOut, OUTPUT);
  meuServo.attach(11);
  tempoInit = millis();
}

void resset() {
  pinMode(reset, OUTPUT);
  digitalWrite(reset, LOW);
}


long medirDistancia() {
  digitalWrite(trigOut, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigOut, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigOut, LOW);
  
  long duracao = pulseIn(echoInput, HIGH);
  
  long distancia = duracao / 58;
  
  return distancia;
  
}

void loop() {
  
  unsigned long tempoAtual = millis();
  medirDistancia();
  
 
  
  	if(medirDistancia() <= 50){
    	meuServo.write(90);
      	if(medirDistancia() <= 50 && tempoAtual - tempoInit >= intervalo){
      digitalWrite(buzzer, HIGH);
      digitaçWrite(led, HIGH);
          	if(medirDistancia() <= 50 && tempoAtual - tempoInit >= intervalo2){
      			meuServo.write(0);
      			digitalWrite(buzzer, LOW);
              digitalWrite(led, LOW);
        		delay(3000);
              	resset();
       		}
    	}
    }else{
      meuServo.write(0);
    }
  
  
}