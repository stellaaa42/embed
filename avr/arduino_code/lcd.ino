#include <LiquidCrystal.h>

// pot:3,77kohm 
// uno_uno: const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;
// 861_uno: const int rs=12, en=13, d4=7, d5=8, d6=9, d7=18;
// 861_sch: const int rs = 1, en = 2, d4 = 3, d5 = 4, d6 = 7, d7 = 8;
// uno_sch: const int rs = 9, en = 8, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;
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
