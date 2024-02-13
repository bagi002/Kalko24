#ifndef MATRIXTASTATURA_H
#define MATRIXTASTATURA_H

#include "Arduino.h"

class Tastatura {
private:
    bool dozvolaCitanja;
    int iR[4];
    int oK[4];
    int x;
    int y;
    char c;
    bool shift;

public:

    Tastatura(int a1, int a2,  int a3, int a4, int b1, int b2, int b3, int b4); //konstruktor objekta 
    int reedMatriks(); // citac x i y kordinata
    String KordinateTest();
    char* reedChar();

};

#endif // MATRIXTASTATURA_H