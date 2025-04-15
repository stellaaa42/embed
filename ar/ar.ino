void setup()
{
  DDRB = B00111111; // Asetetaan Uno pinnit 8–13 (PB0–PB5) output-tilaan
}

void loop()
{
  // LEDit PB0 → PB5
  for (int i = 0; i <= 5; i++) {
    PORTB = (1 << i);  // Sytytetään yksi ledi kerrallaan
    delay(200);
  }

  // LEDit PB4 → PB1 (vältetään PB5 kahdesti)
  for (int i = 4; i >= 0; i--) {
    PORTB = (1 << i);
    delay(200);
  }
}
