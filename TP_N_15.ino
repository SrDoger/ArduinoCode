#include <SoftwareSerial.h>
#define DEBUG true
String dato = "on";
int boton = 5;
int i;
int temp;
int buzzer =13;
int rojo = 11;
int amarillo = 9;
int verde = 6;
int semaforo[3] = {rojo, amarillo, verde};
void setup(){
  pinMode(boton, INPUT);
  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(A5, INPUT);
  Serial.begin(9600);
}

void loop(){
  if(Serial.available() > 0){
    lector();
    Serial.println(dato);
    if(dato == "on"){
      ledsOn();
    }
    else if(dato == "off"){
      ledsOff();
      }
    else if(dato == "temp"){
      lecturaTemp();
      }
  }
}

void ledsOn(){

  for (i = 0; i <= 2; i++){
    delay(3000);
    digitalWrite(semaforo[i], HIGH);
    if(i <= 2){
      digitalWrite(buzzer, HIGH);
      }
  }
}

void ledsOff(){
  for (i = 0; i <= 2; i++){
    delay(3000);
    digitalWrite(semaforo[i], LOW);
    
    if(i <= 2){
      digitalWrite(buzzer, LOW);
      }
  }
}
void lector(){
  String aux = "";
  while( Serial.available()){
    dato = Serial.readString();
  }
}

void lecturaTemp(){
  temp = analogRead(A5);
  temp = map(temp , 20 , 358 , -40 , 125);
  Serial.println(temp);
}
