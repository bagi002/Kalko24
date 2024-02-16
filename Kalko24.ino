#include <TimerOne.h>
#include <LiquidCrystal.h>
#include "header/LCDdriver.h"
#include "header/matrixTastatura.h"
#include "header/Obrada.h"
#include "header/CKB.h"

Ekran displey(12, 13, 8, 9, 10, 11);
Tastatura in(0, 1, 2, 3, 4, 5, 6, 7);

String bafer1 = "";
String bafer2 = "";

int tren = 0;
bool citaj = false;
bool pisi = false;
bool obrada = false;
bool kraj = false;

String t;
 
void prekidRutina(){ // vodi racuna da li treba citati ili pisati u datom trenutku
    tren++;
    if(tren % 2 == 0){
        citaj = true;
    }else{
        citaj = false;
    }

    if(tren % 21 == 0){
        pisi = true;
    }else{
        pisi = false;
    }
}

void obradaCitanja(){ // vrsi obradu citanja
    if(in.reedMatriks() == 1){
        char *c = in.reedChar();
        if(c != NULL){
            if(kraj){
                kraj = false;
                bafer1 = "";
                bafer2 = "";
            }
            bafer1 += *c;
        }
    }  
   
}

void proveraObrade(){
    if(bafer1[bafer1.length()-1] == '='){
        obrada = true;
        bafer1[bafer1.length()-1] = ' ';
    }
}

void obradaPodataka(){
    obrada = false;
    Obrada *proces = new Obrada(bafer1, &bafer2);
    proces -> Analizator();
    delete proces;
    kraj = true;
}

void rukovalacBaferom(){
    CKB::brisanje(&bafer1);
} 

void setup(){
    Timer1.initialize(600);
    Timer1.attachInterrupt(prekidRutina);
}

void loop(){
 
 if(citaj)obradaCitanja();
 rukovalacBaferom();
 if(pisi)displey.pisi(bafer1, bafer2);
 if(pisi)displey.prikaziS(in.isShift());
 proveraObrade();
 if(obrada)obradaPodataka();

}