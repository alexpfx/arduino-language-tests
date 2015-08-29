#include <Wire.h>

long last = 0;
const long millis_wait = 1000;
byte buff[2];

void setup() {
    Serial.begin(9600);
    Wire.begin();
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
    if (c == 'a') {
        return printLuminosity();
    }
    return false;
}

int printLuminosity() {
    init(0x23);
    uint16_t  val = 0;
    if (2 == read(0x23)){
        val=((buff[0]<<8)|buff[1])/1.2;
        Serial.print (val, DEC);
    }
    return true;
    delay (150);
}

int read(int address) {
    int i = 0;
    Wire.beginTransmission(address);
    Wire.requestFrom(address, 2);
    while (Wire.available()) {
        buff[i] = Wire.read();
        i++;
    }
    Wire.endTransmission();
    return i;
}

void init(int address) {
    Wire.beginTransmission(address);
    Wire.write(0x10);
    Wire.endTransmission();
    delay (200);
}
