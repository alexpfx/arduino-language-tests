//lembrete : conectar pino GND antes do VCC para evitar erros segundo o fabricante.
const int trigPin = 11;
const int echoPin =12;
long last = 0;
long millis_wait = 1000;
long x;
float dist;



void setup() {
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);


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
    digitalWrite (trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite (trigPin, HIGH);
    delayMicroseconds (15);
    digitalWrite (trigPin, LOW);
    x = pulseIn (echoPin, HIGH);
    dist = float (x / 58);
    Serial.println (dist);
    return true;
}