#include "../header/Obrada.h"

Obrada::Obrada(String a, String *b){
    rezultat = b;
    podatak = a;
}

Obrada::~Obrada(){

}

String Obrada::racunaj(String x, String y, char op){
    const char* xn = x.c_str();
    double a = atof(xn);
    const char* yn = y.c_str();
    double b = atof(yn);

    double rez;



    switch(op){
        case '+': rez = a + b; break;
        case '-': rez = a - b; break;
        case '*': rez = a * b; break;
        case '/': rez = a / b; break;
    }

    *rezultat = String(rez);
    return String(rez);
}

void Obrada::obradaMD(String *podatakA){
    int pret = -1;
    int op = -1;
    int sl = podatakA->length()-1;
    for(int i = 0; i < podatakA->length()-1;i++){
        if(op == -1){
            if((*podatakA)[i] == '+' || (*podatakA)[i] == '-'){
                pret = i;
            }
            if((*podatakA)[i] == '*' || (*podatakA)[i] == '/'){
                op = i;
            }
        }else{
            if((*podatakA)[i] == '+' || (*podatakA)[i] == '-' || (*podatakA)[i] == '*' || (*podatakA)[i] == '/'){
                sl = i;
                break;
            }
        }  
    }

    if(op != -1){
      String x = podatakA->substring(pret+1,op);
      char ope = (*podatakA)[op];
      String y = podatakA->substring(op+1,sl);
      
      String proracun = racunaj(x, y, ope);

      podatakA->replace(podatakA->substring(pret+1,sl),proracun);
      obradaMD(&podatak);
    }
  
}

void Obrada::obradaPM(String *podatakA){
    int op = -1;
    int op2 = podatakA->length()-1;
     int i = 0;
     if((*podatakA)[0] == '-') i++;
     for(i; i < podatakA->length()-1; i++){
        if((*podatakA)[i] == '+' || (*podatakA)[i] == '-'){
            if(op == -1){
                op = i;
            }else{
                op2 = i;
                break;
            }
        }
     }

     if (op != -1){
      String x = podatakA->substring(0,op);
      if(x.compareTo("") == 0)x=String(0);
      char ope = (*podatakA)[op];
      String y = podatakA->substring(op+1,op2);

      String proracun = racunaj(x, y, ope);
      podatakA->replace(podatakA->substring(0,op2),proracun);
      //*rezultat = String(ope);
      if(op == 0 && op2 == podatakA->length()-1){}else{
        obradaPM(&podatak);
      }
      
     }
}

void Obrada::pretragaZ(String* x){
    int a = -1, b = -1;
    for(int i = 0; i < x->length(); i++){
        if((*x)[i] == '('){
            a = i;
        }
        if((*x)[i] == ')'){
            b = i;
            break;
        }
    }

   if((a != -1 && b == -1) || (a == -1 && b != -1)){
        String m = "Greska " + String(a) + " " + String(b);
        *x = m;
        return;
    }

    if(a != -1 && b != -1){
    String *intern = new String(x->substring(a, b+1));
    String kopija = *intern;
    *intern = intern->substring(1, intern->length() - 1);
    Analizator(intern);
    x->replace(kopija, *intern);
    pretragaZ(x);
    }else{
        return;
    }


}

void Obrada::Analizator(String *x){
    if(x == NULL){
        x = &podatak;0
    }
    pretragaZ(x);
    obradaMD(x);
    obradaPM(x);

    
    if(x == &podatak){
        *x = " = " + *x;
        *rezultat = podatak;
    }
}


