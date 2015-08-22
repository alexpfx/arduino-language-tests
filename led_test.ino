#include <Arduino.h>

int led = 10;

void setup() {
    pinMode(led, OUTPUT);
}

void loop() {

    delay(1000);
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);

}