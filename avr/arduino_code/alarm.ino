
#include <SoftwareSerial.h>
const int rx=3;
const int tx=4;
SoftwareSerial mySerial (rx, tx);

// attiny85 pin6 - arduino 1 
// pin5 - arduino 0
// pin3 - arduino A2
int btn = A2;
const byte led = 1;

int val = 0;


void setup() {
    mySerial.begin(9600);
    pinMode(btn, INPUT);
    pinMode(led, OUTPUT);
}

void loop() {
    // val = analogRead(btn);
    val = digitalRead(btn);
    mySerial.println(val);
    delay(200);

    digitalWrite(led, val);
}

