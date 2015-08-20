#include <Arduino.h>

int pins[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int state [8] = {0, 0, 0, 0, 0, 0, 0, 0};


void setup() {
    Serial.begin(9600);
    for (int i = 0 ; i < 8 ; i++){
        pinMode(pins[i], OUTPUT);
        digitalWrite(pins[i], LOW);
    }


}

void displayNumber(int number) {


}

void loop() {
    for (int i = 0 ; i < 8 ; i++){
        delay (2000);
        state [i] = !state[i];
        digitalWrite(pins[i], state[i]);

    }



}