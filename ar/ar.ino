byte sirros = 0b000001; // Alustetaan: PB0 (pinni 8) on päällä
bool suunta = true;     // true = oikealle (PB0 -> PB5), false = vasemmalle (PB5 -> PB0)

void setup()
{
  DDRB = B00111111;   // Asetetaan Uno pinnit 8–13 (PB0–PB5) output-tilaan
  PORTB = B00000000;  // Sammutetaan kaikki LEDit aluksi
}

void loop()
{
  PORTB = sirros;     // Asetetaan yksittäinen LED päälle
  delay(200);

  // Siirretään bitti suuntaan
  if (suunta) {
    sirros <<= 1;     // Siirrä vasemmalle (PB0 -> PB5)
    if (sirros == 0b100000) {
      suunta = false; // Vaihda suunta kun päästy PB5:een
    }
  } else {
    sirros >>= 1;     // Siirrä oikealle (PB5 -> PB0)
    if (sirros == 0b000001) {
      suunta = true;  // Vaihda suunta kun päästy takaisin PB0:aan
    }
  }
}
