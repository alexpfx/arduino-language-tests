#include <Arduino.h>
#include <math.h>

const int cmd_size = 1;

char recebido [cmd_size];
void setup() {
    Serial.begin(9600);

}


int i = 0;
void loop() {
    if (Serial.available()){
        recebido [i] = Serial.read ();
        i++;
        if (i == cmd_size - 1){
            i = 0;
            recebido [cmd_size - 1] = '\0';
            interpret [recebido];
        }
    }
}

void interpret (char cmd []){



}





