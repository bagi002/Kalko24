#include "../header/LCDdriver.h"

Ekran::Ekran(int rs, int en, int d4, int d5, int d6, int d7) {
    lcd = new LiquidCrystal(rs, en, d4, d5, d6, d7);
    lcd->begin(16, 2);
}

Ekran::~Ekran() {
    delete lcd;
}

void Ekran::Test() {
    lcd->print("Test");
}