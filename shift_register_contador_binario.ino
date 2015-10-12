int latchPin = 12;
int clockPin = 11;
int dataPin = 8;

void setup() {
    Serial.begin (9600);
    delay (1222);
    pinMode (latchPin, OUTPUT);
    pinMode (clockPin, OUTPUT);
    pinMode (dataPin, OUTPUT);


}
int i = 0;

void loopx(){
//  digitalWrite (latchPin, HIGH);
//  digitalWrite (dataPin, HIGH);
//  digitalWrite (clockPin, HIGH);
    delay (200);
    digitalWrite (latchPin, LOW);
    digitalWrite (dataPin, LOW);
    digitalWrite (clockPin, LOW);
    delay (200);

}
void loop() {

    digitalWrite (latchPin, HIGH);
    shiftOut (dataPin, clockPin, MSBFIRST,i);
    digitalWrite (latchPin, LOW);

    i ++;
    if (i > 255) i = 0;
    Serial.println(i);
    delay (5000);
}


void shift (int n){
    for (int i = 0 ; i < 8 ; i ++){
        digitalWrite (clockPin, LOW);
        boolean pinState = (n & (1 << i));
        digitalWrite (dataPin, pinState);
        digitalWrite (clockPin, HIGH);
    }
    digitalWrite (clockPin, LOW);

}

