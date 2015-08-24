int gndDigits[] = {2, 3, 4, 5};
int segArray[] = {6, 7, 8, 9, 10, 11, 12};

/*                 A,B,C,D,E,F,G*/
const int zero[] = {1, 1, 1, 1, 1, 1, 0};
const int one[] = {0, 0, 1, 1, 0, 0, 0};
const int two[] = {1, 1, 0, 1, 1, 0, 1};
const int three[] = {1, 0, 0, 1, 1, 1, 1};
const int four[] = {0, 1, 1, 0, 0, 1, 1};
const int five[] = {1, 0, 1, 1, 0, 1, 1};
const int six[] = {1, 0, 1, 1, 1, 1, 1};
const int seven[] = {1, 0, 1, 1, 0, 0, 0};
const int eight[] = {1, 1, 1, 1, 1, 1, 1};
const int nine[] = {1, 1, 1, 1, 0, 1, 1};

/*
  para mostrar: por o digito que se quer mostrar para low
  e ligar os segmentos.
*/
void setup() {
    Serial.begin(9600);
    for (int i = 0; i < sizeof(gndDigits); i++) {
        pinMode(gndDigits[i], OUTPUT);
        digitalWrite(gndDigits[i], HIGH);
    }

    for (int j = 0; j < sizeof(segArray); j++) {
        pinMode(segArray[j], OUTPUT);
    }


}

void turnOn(const int *const segs) {
    for (int i = 0; i < sizeof(segArray); i++) {
        segArray[i] == segs[i];
    }
}

void turnAll(boolean on, int array[]) {
    for (int i = 0; i < sizeof(array); i++) {
        digitalWrite(on, array[i]);
    }
}

void turnDigit(boolean on, int digit) {
    boolean x = on ? LOW : HIGH;
    digitalWrite(x, digit);
}

#define on true
#define off false

void display(int digit, int value) {
    if (digit >= sizeof(gndDigits) || value < 0 || value > 9) {
        return;
    }
    Serial.println(value);
    turnDigit(on, digit);
    switch (digit) {
        case 0:
            turnOn(zero);
            break;
        case 1:
            turnOn(one);
            break;
        case 2:
            turnOn(two);
            break;
        case 3:
            turnOn(three);
            break;
        case 4:
            turnOn(four);
            break;
        case 5:
            turnOn(five);
            break;
        case 6:
            turnOn(six);
            break;
        case 7:
            turnOn(seven);
            break;
        case 8:
            turnOn(eight);
            break;
        case 9:
            turnOn(nine);
            break;
    }
    delay(1000);
    turnDigit(off, digit);
    turnAll(off, segArray);

}

void loop() {

    display(0, random(1, 9));

}