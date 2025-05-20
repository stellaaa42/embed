// attiny85 pin6-> arduino 1
const byte Btn = 3;
const byte alarm = 1;


void setup() {
    pinMode(Btn);
    Serial.begin(9600);
}

void loop() {
    if (digitalRead(Btn) == HIGH) {
        digitalWrite(alarm) == HIGH;
    }
}
