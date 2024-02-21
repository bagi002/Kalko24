#ifndef OBRADA_H
#define OBRADA_H
#include "Arduino.h"
#include <math.h>

class Obrada{
    private:
        String podatak;
        String *rezultat;

    public:
        void Analizator(String* podatakA = NULL);
        void obradaMD(String*);
        Obrada(String, String*);
        ~Obrada();
        String racunaj(String, String, char);
        void obradaPM(String*);
        void pretragaZ(String*);
};

#endif // OBRADA_H