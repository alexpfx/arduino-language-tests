#define ON true
#define OFF false
#define DEBUG false
#define DEBUG_DELAY 50

int gndDigits[] = {2, 3, 4, 5};
int segArray[] = {6, 7, 8, 9, 10, 11, 12};

/*                 A,B,C,D,E,F,G*/
const int zero[] = {1, 1, 1, 1, 1, 1, 0};
const int one[] = {0, 1, 1, 0, 0, 0, 0};
const int two[] = {1, 1, 0, 1, 1, 0, 1};
const int three[] = {1, 1, 1, 0, 0, 1, 1};
const int four[] = {0, 1, 1, 0, 0, 1, 1};
const int five[] = {1, 0, 1, 1, 0, 1, 1};
const int six[] = {1, 0, 1, 1, 1, 1, 1};
const int seven[] = {1, 1, 1, 0, 0, 0, 0};
const int eight[] = {1, 1, 1, 1, 1, 1, 1};
const int nine[] = {1, 1, 1, 1, 0, 1, 1};

/*
  para mostrar: por o digito que se quer mostrar para low
  e ligar os segmentos.
*/
void setup() {
    Serial.begin(9600);
    debug("setup init");
    for (int i = 0; i < 4; i++) {
        pinMode(gndDigits[i], OUTPUT);
        digitalWrite(gndDigits[i], HIGH);
    }

    for (int j = 0; j < 7; j++) {
        pinMode(segArray[j], OUTPUT);
    }
    debug("setup End");

}

void turnOn(const int *const segs) {
    debug("turnOn init");


    for (int i = 0; i < 7; i++) {
        Serial.println ("segs i");
        Serial.println (i);
        digitalWrite (segArray [i], segs[i]);
    }
    Serial.println("end turnOn");
    Serial.println();
    debug("turnOn end");
}

void turnAll(boolean on, int array[]) {
    debug("turnAll init");
    for (int i = 0; i < 7; i++) {
        digitalWrite(array[i], on);
    }
    debug("turnAll end");
}

void turnDigit(boolean on, int digit) {
    debug("turn digit init");
    boolean x = on? LOW: HIGH;
    debug (x);
    digitalWrite(gndDigits[digit], x);

    debug("turn digit end");
}


void display(int digit, int value) {
    debug("display init");

    if (digit >= 4 || value < 0 || value > 9) {
        return;
    }

    turnDigit(ON, digit);
    switch (value) {
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
    delay (2599);
    turnAll(OFF, segArray);
    turnDigit(OFF, digit);
    debug("display end");

}

void loop() {
    debug("loop init");

    for (int j = 0; j < 4 ; j++){
        for (int i = 0; i < 9 ; i++){
            delay(200);
            display(j, i);
        }
    }

    delay(1000);
    debug("loop end");
}


void debug (char *msg){
    if (DEBUG){
        delay (DEBUG_DELAY);
        Serial.println(msg);
    }

}
void debug (boolean msg){
    if (DEBUG){
        delay (DEBUG_DELAY);
        Serial.println(msg);
    }

}

