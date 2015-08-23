#include <Arduino.h>

int pin = 13;
boolean ligado = false;

void setup() {
    pinMode(pin, OUTPUT);

}

void loop() {

    if (ligado){
        digitalWrite(pin, HIGH);
    } else{
        digitalWrite(pin, LOW);
    }
}