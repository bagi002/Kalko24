#include <TimerOne.h>
#include <LiquidCrystal.h>
#include "header/LCDdriver.h"
#include "header/matrixTastatura.h"


Ekran displey(12, 13, 8, 9, 10, 11);
Tastatura in(0, 1, 2, 3, 4, 5, 6, 7);

String bafer = "=";

void a(){
    int t = in.reedMatriks();
    String f = "Test " + String(t);
    char *priv = in.reedChar();
    if(priv != NULL){
        bafer += *priv;
     }
    displey.pisi(f, bafer);
}

void setup(){
    //Timer1.initialize(25000);
    
    //Timer1.attachInterrupt(a);
}

void loop(){
    a();
    delay(1);
}