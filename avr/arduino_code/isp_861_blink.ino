/*
  arduino uno -> flash uno board as arduinoISP -> connect the 861 board and switch board
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // LED_BUILTIN=pin8
  pinMode(8, OUTPUT);
}

void loop() {
  digitalWrite(8, HIGH); 
  delay(1000);  
  digitalWrite(8, LOW);  
  delay(1000);  
}
