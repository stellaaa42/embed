
#include <SoftwareSerial.h>
const int rx=3;
const int tx=4;
SoftwareSerial mySerial (rx, tx);

// attiny85 pin3 - arduino A2, pin2-arduinoA3, pin1-reset, pin7-arduinoA1
// pin5 - arduino 0 pwm
// pin6 - arduino 1 pwm
int btn = A2;
const byte led = 1;
const byte buzzer = 0;

int val = 0;


void setup() {
//    mySerial.begin(9600);
    pinMode(btn, INPUT);
    pinMode(led, OUTPUT);
    pinMode(buzzer, OUTPUT);
}

void loop() {
    // val = analogRead(btn);
    val = digitalRead(btn);
//    mySerial.println(val);
    delay(200);

    digitalWrite(led, val);
    digitalWrite(buzzer, val);
}
