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
        String bafer1d;

        if(bafer1.length() > 16){
            bafer1d = bafer1.substring(bafer1.length()-16,bafer1.length());
        }else{
            bafer1d = bafer1;
        }

        lcd->clear();
        lcd->setCursor(0, 0);
        lcd->print(bafer1d);
        lcd->setCursor(0, 1);
        lcd->print(bafer2);
    }
}

void Ekran::prikaziS(bool x){
    if(x != shift){
        shift = !shift;
        if(shift){
            lcd->setCursor(1, 15);
            lcd->print("s");
        }else{
            lcd->setCursor(1, 15);
            lcd->print(" ");
        }
    }
}
