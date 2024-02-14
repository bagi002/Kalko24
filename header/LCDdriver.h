#ifndef LCDDRIVER_H
#define LCDDRIVER_H

#include <LiquidCrystal.h>
#include "Arduino.h"

class Ekran {
private:
    LiquidCrystal *lcd;
    String bafer1;
    String bafer2;
    bool shift;

public:
    Ekran(int rs, int en, int d4, int d5, int d6, int d7);
    ~Ekran();
    void Test();
    void pisi(String a, String b);
    void prikaziS(bool x);
};

#endif // LCDDRIVER_H