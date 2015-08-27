#include <Wire.h>
#include <math.h>
#include <Arduino.h>

int bh1750add = 0x23;
byte buff[2];

void setup() {
    Wire.begin();
    Serial.begin(9600);

}

void loop() {
    int i;
    uint16_t val = 0;
    bhInit(bh1750add);
    delay(200);

    if (2 == bhRead(bh1750add)) {

        val = (buff[0] << 8 | buff[1]) / 1.2;
        Serial.print(val, DEC);
        Serial.println ();
    }
    delay(150);

}


int bhRead(int address) {
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

void bhInit(int address) {
    Wire.beginTransmission(address);
    Wire.write(0x10);
    Wire.endTransmission();
}
