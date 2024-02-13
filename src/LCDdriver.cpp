#include "../header/LCDdriver.h"

Ekran::Ekran(int rs, int en, int d4, int d5, int d6, int d7) {
    lcd = new LiquidCrystal(rs, en, d4, d5, d6, d7);
    lcd->begin(16, 2);
    bafer1 = " ";
    bafer2 = " ";
}

Ekran::~Ekran() {
    delete lcd;
}

void Ekran::Test() {
    lcd->print("Test");
}

void Ekran::pisi(String a, String b){
    if(a.compareTo(bafer1) != 0 || b.compareTo(bafer2) != 0){
        bafer1 = a;
        bafer2 = b;
        lcd->clear();
        lcd->setCursor(0, 0);
        lcd->print(bafer1);
        lcd->setCursor(0, 1);
        lcd->print(bafer2);
    }
}