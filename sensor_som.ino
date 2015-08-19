#include <Arduino.h>


int led = 13;

void setup() {
    Serial.begin(9600);
    pinMode(A0, INPUT);
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
}

void loop() {
    int sound = analogRead(A0);
    Serial.println(sound);


}