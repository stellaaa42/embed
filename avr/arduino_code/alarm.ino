const byte Btn = 3;
const byte alarm = 6;


void setup() {
    pinMode(Btn);
    Serial.begin(9600);
}

void loop() {
    if (digitalRead(Btn) == HIGH) {
        digitalWrite(alarm) == HIGH
    }
}