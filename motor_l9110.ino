int motorIa = 10;
int motorIb = 11;
int slow = 50;
int fast = 150;
int superFast = 240;


void setup() {

    pinMode(motorIa, OUTPUT);
    pinMode(motorIb, OUTPUT);
    digitalWrite(motorIa, LOW);
    digitalWrite(motorIb, LOW);
    Serial.begin(9600);


}

void loop() {
    boolean isValid;

    do {
        byte c;
        while (!Serial.available());

        Serial.print("read");
        c = Serial.read();

        switch (c) {
            case '1' :
                stopMotor();
                digitalWrite(motorIb, HIGH);
                analogWrite(motorIa, 255 - slow);
                isValid = true;
                Serial.print("slow");
                break;
            case '2' :
                stopMotor();
                digitalWrite(motorIb, HIGH);
                analogWrite(motorIa, 255 - fast);
                isValid = true;
                break;
            case '2' :
                stopMotor();
                digitalWrite(motorIb, HIGH);
                analogWrite(motorIa, 255 - fast);
                isValid = true;
                break;

            case '3' :
                stopMotor();
                isValid = true;
                break;
            default :
                stopMotor();
                isValid = false;
                break;
        }
    } while (isValid);
}


void stopMotor() {
    digitalWrite(motorIa, LOW);
    digitalWrite(motorIb, LOW);
    delay(1000);

}
