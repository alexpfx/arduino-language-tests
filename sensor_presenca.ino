#include <Arduino.h>
int led = 13;
int in = 7;
void setup() {
    pinMode(led, OUTPUT);
    pinMode(in, INPUT);
}

void loop() {
    delay(100);
    int o = digitalRead(in);
    digitalWrite(led, o);
}