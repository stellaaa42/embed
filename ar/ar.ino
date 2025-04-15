// stella 15.4.2025
const byte ledPin[] = {7, 8, 9, 10, 11, 12, 13}; // A–G (järjestyksessä)

byte i = 0; // for-loopin muuttuja

void setup() {
  // Määritellään pinneille OUTPUT-tila
  for (i = 0; i < 7; i++) {
    pinMode(ledPin[i], OUTPUT);
  }

  // Näytetään numero 3: segmentit a, b, c, d ja g päälle (HIGH)
  digitalWrite(ledPin[0], HIGH); // a
  digitalWrite(ledPin[1], HIGH); // b
  digitalWrite(ledPin[2], HIGH); // c
  digitalWrite(ledPin[3], HIGH); // d
  digitalWrite(ledPin[6], HIGH); // g

  // Loput segmentit pois (LOW): e ja f
  digitalWrite(ledPin[4], LOW);  // e
  digitalWrite(ledPin[5], LOW);  // f
}

void loop() {
  // Ei toistoa tarvitse
}
