#include <Arduino.h>
#include <BH1750FVI/BH1750FVI.h>

BH1750FVI lightMeter;


void setup() {
    Serial.begin(9600);
    lightMeter.begin();


}

void loop() {
    uint16_t  lux = lightMeter.GetLightIntensity();
    Serial.print("Light: ");
    Serial.println(lux);
    delay(500);
}