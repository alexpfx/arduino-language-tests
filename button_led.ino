#include <Arduino.h>

int pin = 10;
int led= 8;
boolean ligado = false;

void setup() {
    Serial.begin(9600);
    pinMode(pin, INPUT);
    pinMode(led, OUTPUT);
    digitalWrite (pin, 1);
    digitalWrite (led, 0);


}

void loop() {
    ligado = !digitalRead(pin);
    if (ligado)
        digitalWrite (led, HIGH);
    else
        digitalWrite(led, LOW);



}