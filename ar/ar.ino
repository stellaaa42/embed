const int buttonPin = 2;       // Nappi
const int led1 = 13;           // Ledi 1
const int led2 = 12;           // Ledi 2
const int led3 = 11;           // Ledi 3

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    // Sytytä kaikki kolme lediä
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(200);

    // Sammuta kaikki
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(200);
  }
}
