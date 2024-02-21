#include "../header/matrixTastatura.h"



Tastatura::Tastatura(int a1, int a2,  int a3, int a4, int b1, int b2, int b3, int b4){
    iR[0] = a1;
    iR[1] = a2;
    iR[2] = a3;
    iR[3] = a4;

    oK[0] = b1;
    oK[1] = b2;
    oK[2] = b3;
    oK[3] = b4;

    for(int i = 0; i <= 3; i++){
        pinMode(iR[i], OUTPUT);
        pinMode(oK[i], INPUT);
        digitalWrite(iR[i], LOW);
    }

    x = -1;
    y = -1;
    dozvolaCitanja = true;
}

int Tastatura::reedMatriks(){
 for(int i = 0; i<= 3; i++){
    digitalWrite(iR[i],HIGH);
    for(int j = 0; j <= 3; j++){
      if(digitalRead(oK[j]) == HIGH){
        x = i;
        y = j;
        digitalWrite(iR[i],LOW);
        return 1;
      }
    }
    digitalWrite(iR[i],LOW);
  }
  dozvolaCitanja = true;
  return 0;
}

String Tastatura::KordinateTest(){
    String s = "Red: " + String(x) + " | Kol: " + String(y); 
    return s;
}

char* Tastatura::reedChar(){
  char *z = new char();
    if(dozvolaCitanja && reedMatriks() == 1){
      dozvolaCitanja = false;
      int n = x*10 + y;
      if(!shift){
        switch (n){
          case 00: *z='1'; break;
          case 01: *z='2'; break;
          case 02: *z='3'; break;
          case 03: *z='+'; break;
          case 10: *z='4'; break;
          case 11: *z='5'; break;
          case 12: *z='6'; break;
          case 13: *z='-'; break;
          case 20: *z='7'; break;
          case 21: *z='8'; break;
          case 22: *z='9'; break;
          case 23: *z='*'; break;
          case 30: shift = !shift; delete z; return NULL; break;
          case 31: *z='0'; break;
          case 32: *z='='; break;
          case 33: *z='/'; break;
        }
      }else{
        switch (n){
          case 00: *z='('; break;
          case 01: *z=')'; break;
          case 02: *z='3'; break;
          case 03: *z='+'; break;
          case 10: *z='4'; break;
          case 11: *z='5'; break;
          case 12: *z='6'; break;
          case 13: *z='-'; break;
          case 20: *z='7'; break;
          case 21: *z='8'; break;
          case 22: *z='9'; break;
          case 23: *z='*'; break;
          case 30: shift = !shift; delete z; return NULL; break;
          case 31: *z='d'; break;
          case 32: *z='='; break;
          case 33: *z='.'; break;
        }
      }

      return z;
    }
     delete z;
     return NULL;
}

bool Tastatura::isShift(){
  return shift;
}