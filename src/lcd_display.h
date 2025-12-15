#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H

#include <LCD_I2C.h>

LCD_I2C lcd(0x27);

void initLCD() {
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.print("IoT BP Monitor");
}

void showPressure(int sys, int dia) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("SYS: ");
  lcd.print(sys);
  lcd.print(" mmHg");

  lcd.setCursor(0,1);
  lcd.print("DIA: ");
  lcd.print(dia);
  lcd.print(" mmHg");
}

#endif

