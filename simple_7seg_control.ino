/**
 * Controle um display de 7 segmentos:
 * Entrada: numero representando segmento e status desejado, exemplo:
 *          
 *
 */

#include <Arduino.h>
#include <ctype.h> 


int pins[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int state[8] = {0, 0, 0, 0, 0, 0, 0, 0};


void setup() {
    Serial.begin(9600);
    Serial.println("escutando");
    for (int i = 0; i < 8; i++) {
        pinMode(pins[i], OUTPUT);
        digitalWrite(pins[i], LOW);
    }
}

void segOnOf(int seg, boolean value) {
    Serial.println(value);
    digitalWrite(pins[seg], value);
}

long cmd;

void loop() {

    int cmd = getNumberFromSerial();
    Serial.print(cmd);
    if (cmd < 0 || cmd > 7) {
        delay(1000);
        Serial.println("saindo");
        exit(0);
    }
    state[cmd] = !state[cmd];
    segOnOf(cmd, state[cmd]);
}


int getNumberFromSerial(void) {
    int av = 0;
    while (av == 0){
        av = Serial.available();
    }
    char buffer[10];
    Serial.readBytes(buffer, av);
    Serial.flush();
    return atoi(buffer);

}