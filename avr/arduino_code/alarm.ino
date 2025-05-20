// attiny85 pin6 - arduino 1 
// pin5 - arduino 0
// pin3 - arduino A2
int btn = A2;
const byte led = 1;

int val = 0;


void setup() {
    pinMode(btn, INPUT);
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // val = analogRead(btn);
    val = digitalRead(btn);
    Serial.prinln(val);
    delay(200);

    digitalWrite(led, val);
}
