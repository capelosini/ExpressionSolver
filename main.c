#include "include/ESolver.h"

int main(){
    EObject* obj = parseExpression("(5+2)/2", 1);
    if (obj == NULL){
        return 1;
    }
    freeExpression(obj);
    return 0;
}
