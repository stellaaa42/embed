const byte ledPin[] = {7, 8, 9, 10, 11, 12, 13};
const byte nappiPin = 2;

bool nappiPainettu = false;

void setup() {
  for (byte i = 0; i < 7; i++) {
    pinMode(ledPin[i], OUTPUT);
  }

  pinMode(nappiPin, INPUT_PULLUP);
  Serial.begin(9600);
  randomSeed(analogRead(A0));
}

void loop() {
  if (digitalRead(nappiPin) == LOW && !nappiPainettu) {
    nappiPainettu = true;

    int luku = random(1, 7);
    Serial.println(luku);
    naytaNumero(luku);

    delay(200);
  }

  if (digitalRead(nappiPin) == HIGH && nappiPainettu) {
    nappiPainettu = false;
  }
}

void naytaNumero(int numero) {
  for (byte i = 0; i < 7; i++) {
    digitalWrite(ledPin[i], LOW);
  }

  switch (numero) {
    case 1:
      digitalWrite(ledPin[1], HIGH);
      digitalWrite(ledPin[2], HIGH);
      break;
    case 2:
      digitalWrite(ledPin[0], HIGH);
      digitalWrite(ledPin[1], HIGH);
      digitalWrite(ledPin[6], HIGH);
      digitalWrite(ledPin[4], HIGH);
      digitalWrite(ledPin[3], HIGH);
      break;
    case 3:
      digitalWrite(ledPin[0], HIGH);
      digitalWrite(ledPin[1], HIGH);
      digitalWrite(ledPin[2], HIGH);
      digitalWrite(ledPin[3], HIGH);
      digitalWrite(ledPin[6], HIGH);
      break;
    case 4:
      digitalWrite(ledPin[1], HIGH);
      digitalWrite(ledPin[2], HIGH);
      digitalWrite(ledPin[5], HIGH);
      digitalWrite(ledPin[6], HIGH);
      break;
    case 5:
      digitalWrite(ledPin[0], HIGH);
      digitalWrite(ledPin[2], HIGH);
      digitalWrite(ledPin[3], HIGH);
      digitalWrite(ledPin[5], HIGH);
      digitalWrite(ledPin[6], HIGH);
      break;
    case 6:
      digitalWrite(ledPin[0], HIGH);
      digitalWrite(ledPin[2], HIGH);
      digitalWrite(ledPin[3], HIGH);
      digitalWrite(ledPin[4], HIGH);
      digitalWrite(ledPin[5], HIGH);
      digitalWrite(ledPin[6], HIGH);
      break;
  }
}
