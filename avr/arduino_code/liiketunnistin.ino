// attiny85 - arduino
// pin3 - arduino4&a2
// pin7 - arduino2
// pin2 - arduino3&a3
// pin1-reset, pin6 - arduino1, pin2-arduino3, pin1-reset, pin7-arduino2&a1, pin5 - arduino0
uint8_t motion = A2;
uint8_t sw = 2;
uint8_t base = 3;
uint8_t swVal;
uint8_t sensorVal;
uint8_t outpVal;

void setup() {
    pinMode(motion, INPUT);
    pinMode(sw, INPUT);
    pinMode(base, OUTPUT);
//    Serial.begin(9600);
}

void loop() {
    sensorVal = analogRead(motion);
    swVal = digitalRead(sw);
    outpVal = map(sensorVal, 900, 0, 0, 255);
//    Serial.print(swVal);
//    Serial.print("\t");
//    Serial.print(sensorVal);
//    Serial.print("\t");
//    Serial.println(outpVal);
//    delay(500);
    if (swVal == HIGH && outpVal > 200) {
      digitalWrite(base, HIGH);
    } else {
      digitalWrite(base, LOW);
    }
}
