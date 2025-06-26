// attiny85 pin3 - arduino4&a2
// pin5 - arduino0 
// pin6 - arduino1
// pin2-arduino3&a3, pin1-reset, pin7-arduino2, pin2-arduino3, pin1-reset, pin7-arduino2&a1
const int motion = 4;
const int led = 1;
const int buzzer = 0;


void setup() {
    pinMode(motion, INPUT);
    pinMode(led, OUTPUT);
    pinMode(buzzer, OUTPUT);
}

void loop() {
    int val = digitalRead(motion);

    if (val== HIGH) {
      for (int i=0; i<=2; i++)
      {
        digitalWrite(buzzer, HIGH);

        for (int j = 0; j < 5; j++) {  
          digitalWrite(led, HIGH);
          delay(100);
          digitalWrite(led, LOW);
          delay(100);
        }
        digitalWrite(buzzer, LOW);
      }
    } else {
        digitalWrite(led, HIGH);
        digitalWrite(buzzer, LOW);
    }
}
