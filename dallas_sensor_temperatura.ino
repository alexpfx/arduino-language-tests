#include <OneWire.h>

#include <DallasTemperature.h>

#include "SevSeg.h"

SevSeg sevseg;
int x = 0;
int pinTemp = 13;

OneWire oneWire (pinTemp);
DallasTemperature sensors (&oneWire);
float temp = 0;
// Assign the addresses of your 1-Wire temp sensors.
DeviceAddress InThermo = {
        0x28, 0x69, 0xC2, 0xB0, 0x03, 0x00, 0x00, 0X9F };
DeviceAddress OutThermo = {
        0x28, 0x7A, 0x8B, 0xC0, 0x03, 0x00, 0x00, 0x2F };

long interval = 15500;
long prevmillis = millis ();

void setup() {
    byte numDigits = 3;
    byte digitPins[] = {2, 3, 4};
    byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 5};
    sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
    sevseg.setBrightness(1);
    sensors.begin ();
    sensors.setResolution(InThermo, 12);
    sensors.setResolution(OutThermo, 12);

    delay(1000);
    Serial.begin (9600);



}

void loop() {


    if ((millis () - prevmillis) > interval){
        prevmillis = millis ();
        Serial.println (millis());
        sensors.requestTemperatures();
        delay (1000);
        temp = sensors.getTempCByIndex(0);
    }
    sevseg.setNumber (temp,1);
    sevseg.refreshDisplay();

}