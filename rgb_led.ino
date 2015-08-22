#include <Arduino.h>
int r = 8;
int g = 9;
int b = 10;

void setup() {
    pinMode(r, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(b, OUTPUT);
}

void loop() {

    digitalWrite(r, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(b, HIGH);

    delay(2000);

    digitalWrite(r, LOW);


    delay(2000);

    digitalWrite(g, LOW);


    delay(2000);

    digitalWrite(b, LOW);



}