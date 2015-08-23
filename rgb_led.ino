#include <Arduino.h>

int r = 8;
int g = 9;
int b = 10;

void setup() {
    pinMode(r, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(b, OUTPUT);
}

int cr = 0;
int cg = 0;
int cb = 0;

void loop() {

    analogWrite(r, cr++);


    delay(20);

    analogWrite(g, cg++);

    delay(20);

    analogWrite(b, cb++);

    delay(20);


    if (cr == 255) {
        cr = 1;
    }
    if (cb == 255) {
        cb = 1;
    }
    if (cg == 255) {
        cg = 1;

    }


}