void setup() {
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(1, HIGH);  // RS HIGH
  digitalWrite(2, HIGH);  // EN HIGH
  delay(500);
  digitalWrite(1, LOW);   // RS LOW
  digitalWrite(2, LOW);   // EN LOW
  delay(500);
}
