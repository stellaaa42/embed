#include <LiquidCrystal.h>

// pot:3,77kohm 
// pot1602: 1,3kohm
// uno_uno: const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;
// sch_uno: const int rs=9, en=8, d4=7, d5=6, d6=5, d7=4;
const int rs=9, en=8, d4=7, d5=6, d6=5, d7=4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String str="hello, world!";

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print(millis()/1000);
  
  lcd.setCursor(0,1);
  lcd.print(str);

  delay(1000);
}