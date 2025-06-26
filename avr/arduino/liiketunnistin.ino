// attiny85 - arduino
// pin3 - arduino4&a2 ldr
// pin5 - arduino0 sw
// pin6 - arduino1 base led
// pin1-reset, pin7 - arduino2, pin2 - arduino3&a3, pin2-arduino3, pin1-reset, pin7-arduino2&a1
uint8_t ldr = A2;
uint8_t sw = 0;
uint8_t base = 1;
uint8_t swVal;
uint8_t sensorVal;
uint8_t outpVal;

void setup() {
    pinMode(ldr, INPUT);
    pinMode(sw, INPUT);
    pinMode(base, OUTPUT);
//    Serial.begin(9600);
}

void loop() {
    sensorVal = analogRead(ldr);
    swVal = digitalRead(sw);
    outpVal = map(sensorVal, 900, 0, 0, 255);
// for testing:
//    digitalWrite(base,HIGH);
//    delay(200);
//    digitalWrite(base,LOW);
//    delay(100);
    
//    Serial.print(swVal);
//    Serial.print("\t");
//    Serial.print(sensorVal);
//    Serial.print("\t");
//    Serial.println(outpVal);
//    delay(500);

    if (swVal == HIGH && outpVal > 228) {
      digitalWrite(base, HIGH);
    } else {
      digitalWrite(base, LOW);
    }


}
