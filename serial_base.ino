long last = 0;
const long millis_wait = 1000;

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
    if (c == 't') {
        return getTemperature();
    }
    return false;
}



