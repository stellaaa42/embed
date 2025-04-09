// Stella 9.4.2025
const int button1Pin = 2;
const int led1Pin = 9;

const int button2Pin = 4;
const int led2Pin = 12;

void setup() {
  pinMode(button1Pin, INPUT);
  pinMode(led1Pin, OUTPUT);

  pinMode(button2Pin, INPUT);
  pinMode(led2Pin, OUTPUT);
}

void loop() {
  // Lue nappien tilat
  int button1State = digitalRead(button1Pin);
  int button2State = digitalRead(button2Pin);

  // Jos nappia 1 painetaan, vilkuta ledi 1
  if (button1State == HIGH) {
    digitalWrite(led1Pin, HIGH);
    delay(200);
    digitalWrite(led1Pin, LOW);
    delay(200);
  }

  // Jos nappia 2 painetaan, vilkuta ledi 2
  if (button2State == HIGH) {
    digitalWrite(led2Pin, HIGH);
    delay(200);
    digitalWrite(led2Pin, LOW);
    delay(200);
  }
}
