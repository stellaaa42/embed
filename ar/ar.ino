void setup() {
    Serial.begin(9600);
  }
  
  void loop() {
    int sensorValue = analogRead(A0);        
    int scaledValue = map(sensorValue, 0, 1023, 0, 10); 
    Serial.println(scaledValue);             
    delay(500);          
  }gtia