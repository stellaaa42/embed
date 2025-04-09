int ledPin1 = 9;
int ledPin2 = 10;
int buttonPin = 2;

int brightness = 0;
int fadeAmount = 10;

int buttonState = 0;
int lastButtonState = HIGH;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Käytetään sisäistä pullupia

  brightness = 0;
  buttonState = 0;

  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  // Tarkistetaan onko nappia juuri painettu (reunatunnistus)
  if (lastButtonState == HIGH && buttonState == LOW) {
    brightness += fadeAmount;

    if (brightness > 255) {
      brightness = 0; // Palautetaan nollaan, kun yli maksimin
    }

    analogWrite(ledPin1, brightness);
    analogWrite(ledPin2, brightness);

    Serial.print("PWM-arvo (brightness): ");
    Serial.println(brightness);

    delay(200); // Debounce-viive
  }

  lastButtonState = buttonState;
}
