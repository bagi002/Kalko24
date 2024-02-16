#include "../header/Obrada.h"

Obrada::Obrada(String a, String *b){
    rezultat = b;
    podatak = a;
}

Obrada::~Obrada(){

}

String Obrada::racunaj(String x, String y, char op){
    const char* xn = x.c_str();
    int a = atoi(xn);
    const char* yn = y.c_str();
    int b = atoi(yn);

    int rez;

    switch(op){
        case '+': rez = a + b; break;
        case '-': rez = a - b; break;
        case '*': rez = a * b; break;
        case '/': rez = a / b; break;
    }

    return String(rez);
}

void Obrada::obradaMD(){
    int pret = -1;
    int op = -1;
    int sl = podatak.length()-1;
    for(int i = 0; i < podatak.length()-1;i++){
        if(op == -1){
            if(podatak[i] == '+' || podatak[i] == '-'){
                pret = i;
            }
            if(podatak[i] == '*' || podatak[i] == '/'){
                op = i;
            }
        }else{
            if(podatak[i] == '+' || podatak[i] == '-' || podatak[i] == '*' || podatak[i] == '/'){
                sl = i;
                break;
            }
        }  
    }

    if(op != -1){
      String x = podatak.substring(pret+1,op);
      char ope = podatak[op];
      String y = podatak.substring(op+1,sl);
      
      String proracun = racunaj(x, y, ope);

      podatak.replace(podatak.substring(pret+1,sl),proracun);
      obradaMD();
    }
  
}

void Obrada::obradaPM(){
    int op = -1;
    int op2 = podatak.length()-1;
     int i = 0;
     if(podatak[0] == '-') i++;
     for(i; i < podatak.length()-1; i++){
        if(podatak[i] == '+' || podatak[i] == '-'){
            if(op == -1){
                op = i;
            }else{
                op2 = i;
                break;
            }
        }
     }

     if (op != -1){
      String x = podatak.substring(0,op);
      if(x.compareTo("") == 0)x=String(0);
      char ope = podatak[op];
      String y = podatak.substring(op+1,op2);

      String proracun = racunaj(x, y, ope);
      podatak.replace(podatak.substring(0,op2),proracun);
      //*rezultat = String(ope);
      if(op == 0 && op2 == podatak.length()-1){}else{
        obradaPM();
      }
      
     }

}

void Obrada::Analizator(){
    obradaMD();
    obradaPM();

    podatak = " = " + podatak;
    *rezultat = podatak;
}
