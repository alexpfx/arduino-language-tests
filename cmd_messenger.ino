#include <CmdMessenger.h>
#include <OneWire.h>
#include <DallasTemperature.h>

int pinTemp = 13;

CmdMessenger cmdMessenger = CmdMessenger(Serial);
OneWire oneWire(pinTemp);
DallasTemperature sensors(&oneWire);


enum {
    kReadTemperature,
    kStatus,
};

void attachCommandCallbacks() {
    cmdMessenger.attach(onUnknownCommand);
    cmdMessenger.attach(kReadTemperature, onReadTemperature);
}

void onStatus() {
    Serial.println("status");

}

void onUnknownCommand() {
    Serial.println("unknow");
}

void onReadTemperature() {
    Serial.println("readTemp");
    sensors.requestTemperatures();
    delay(1500);
    float temp = sensors.getTempCByIndex(0);
    cmdMessenger.sendCmd(kStatus, (float) temp);

}

void setup() {
    Serial.begin(115200);
    sensors.begin();
    cmdMessenger.printLfCr();
    attachCommandCallbacks();


}

void loop() {
    cmdMessenger.feedinSerialData();


}