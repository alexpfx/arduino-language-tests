#include <Arduino.h>

int pins[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int matrix[10][8] = {{1, 1, 1, 1, 1, 1, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0}
};

void setup() {
    for (int i = 0; i < 8; i++) {
        pinMode(pins[i], OUTPUT);
        digitalWrite(pins[i], LOW);
        Serial.begin(9600);
    }

}

void displayNumber (int number){
    if (number < 0 || number > 9){
        return;
    }
    for (int i = 0; i < 8; i++){
        Serial.println(matrix[number, i]);
    }
}
void loop() {
    delay(1000);
    displayNumber(8);


}