#ifndef LCDDRIVER_H
#define LCDDRIVER_H

#include <LiquidCrystal.h>
#include "Arduino.h"

class Ekran {
private:
    LiquidCrystal *lcd;

public:
    Ekran(int rs, int en, int d4, int d5, int d6, int d7);
    ~Ekran();
    void Test();
};

#endif // LCDDRIVER_H