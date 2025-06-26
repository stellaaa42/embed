//lataa AtTiny861 piirille ensin käynnistyksen lataaja (Bootloader), sitten vasta ohjelma!

#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define AVERAGING_VALUES_COUNT 5 
#define ONE_WIRE_BUS 3			//Määritellään OneWire pinni

// sch_uno: const int rs=9, en=8, d4=7, d5=6, d6=5, d7=4;
// sch: 18, 14, 13, 12, 11, 8; 
// sch0_uno: const int rs=2, en=10, d4=11, d5=12, d6=13, d7=4;
const byte rs=2, en=10, d4=11, d5=12, d6=13, d7=4;	//Määritellään LCD näytön pinnit
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress sensor0, sensor1; 

void setup() {

  lcd.begin(16, 2);
  lcd.clear();
  sensors.begin();
  sensors.setResolution(sensor0, 9); // pistä sensorien resoluutio 9 bittiin
  sensors.setResolution(sensor1, 9);
  lcd.print("Digital T-meter");
  lcd.setCursor(0, 1);
  lcd.print("Found ");
  lcd.print(sensors.getDeviceCount());
  lcd.print(" sensor/s");

  delay(1500);

  for (byte i = 0; i < AVERAGING_VALUES_COUNT; i++) {
    readTemp(0);
    readTemp(1);
  }
  lcd.clear();
}

void loop() {
  updateLCD();
  delay(500);
}

void updateLCD(){
  char linebuffer[17];
  float sensor0temp = readTemp(0);
  float sensor1temp = readTemp(1);
  
  lcd.setCursor(0,0);
  sprintf(linebuffer, "Interior: %2d.%1dC", (int)sensor0temp, abs((int)(sensor0temp * 10) % 10));
  lcd.print(linebuffer);
  lcd.setCursor(0,1);
  sprintf(linebuffer, "Exterior: %2d.%1dC", (int)sensor1temp, abs((int)(sensor1temp * 10) % 10));
  lcd.print(linebuffer);
}

float readTemp(byte index) {
  float temperature;
  static byte averagingIteration;
  static float readings[2][AVERAGING_VALUES_COUNT];

    sensors.requestTemperatures();
    temperature = sensors.getTempCByIndex(index);
    if (temperature == DEVICE_DISCONNECTED_C) {
       return -99.9; 
    }

  readings[index][averagingIteration] = temperature;
  
  averagingIteration++;
  if (averagingIteration >= AVERAGING_VALUES_COUNT)
     averagingIteration = 0;
  

  float avgTemperature = 0;
  for (byte i = 0; i < AVERAGING_VALUES_COUNT; i++) {
      avgTemperature += readings[index][i];
  }
  return avgTemperature / AVERAGING_VALUES_COUNT;
}