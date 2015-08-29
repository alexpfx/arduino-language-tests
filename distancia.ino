#include <NewPing.h>


const float SOUND_SPEED = 340.29; //metros por segundo.
//lembrete : conectar pino GND antes do VCC para evitar erros segundo o fabricante.
int trigPin = 9;
int echoPin = 8;
long last = 0;
long millis_wait = 1000;
float distance;

NewPing sonar(trigPin, echoPin, 400);


void setup() {
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    digitalWrite(trigPin, LOW);
    digitalRead (echoPin);


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
    int uS = sonar.ping();
    Serial.println(uS / US_ROUNDTRIP_CM);

    return true;
}