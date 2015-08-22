#include <Arduino.h>

int led1 = 9;
int led2 = 10;
void setup() {
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
}

void loop() {
    delay(2000);
    digitalWrite(9, HIGH);
    delay(2000);
    digitalWrite(10,HIGH);
    delay(2000);
    digitalWrite(9, LOW);
    delay(2000);
    digitalWrite(10,LOW);

}