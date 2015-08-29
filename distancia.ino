#include <Arduino.h>
const float SOUND_SPEED = 340.29; //metros por segundo.

int trigPin = 9;
int echoPin = 8;
long last = 0;
long millis_wait = 1000;
float distance;

void setup() {
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    digitalWrite(trigPin, LOW);
}

void loop() {
    if (Serial.available()) {
        char c = Serial.read();
        if (((millis() - last) > millis_wait)) {
            if (interpret(c)) {
                last = millis();
            }
        }
    }
}

boolean interpret(char c) {
    if (c == 't') {
        return printDistance();
    }
    return false;
}


boolean printDistance (){
    digitalWrite (trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite (trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    distance = pulseIn(echoPin, HIGH) / 58 ; // cm
    Serial.println(distance);

    return true;
}