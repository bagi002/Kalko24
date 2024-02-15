#include "../header/CKB.h"

void CKB::brisanje(String *x){
    if((*x)[x->length()-1] == 'd'){
        (*x) = x->substring(0, x->length() - 2);
    }
}