#ifndef OBRADA_H
#define OBRADA_H
#include "Arduino.h"

class Obrada{
    private:
        String podatak;
        String *rezultat;

    public:
        void Analizator();
        void obradaMD();
        Obrada(String, String*);
        ~Obrada();
        String racunaj(String, String, char);
        void obradaPM();
};

#endif // OBRADA_H