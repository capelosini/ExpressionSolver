#include "ESolver.h"
#include <string.h>

unsigned char verifyExpression(char* exp){
    // checks vars
    char allowed[]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', '+', '*', '/', '(', ')', '.'};
    int allowedLen = 16;
    int oBrackets=0;
    int cBrackets=0;
    char prevChar=0;
    // check loop
    for (int i=0; i<strlen(exp); i++){
        char l = exp[i];
        // forbidden chars check
        if (l<0x28 || l>0x39){
            printf("'%c' is not allowed!\n", l);
            return 0;
        }
        for (int j=0; j<allowedLen; j++){
            if (l==allowed[j]){
                break;
            }
            else if (j+1 == allowedLen){
                printf("'%c' is not allowed!\n", l);
                return 0;
            }
        }
        // switch to checks
        switch (l) {
            case '(':
                oBrackets++;
                break;
            case ')':
                cBrackets++;
                if (cBrackets>oBrackets){
                    printf("Invalid Brackets!\n");
                    return 0;
                }
                break;
        }
        // two or more operators together
        // if ((l>=0x28 && l<=0x2F) && (prevChar>=0x28 && prevChar<=0x2F)){
        //     printf("'%c%c' ?\n", prevChar, l);
        //     return 0;
        // }
        // end of chars in expression
        if (i == strlen(exp)-1){
            // invalid brackets number
            if (cBrackets != oBrackets){
                printf("Invalid Brackets!\n");
                return 0;
            }
        }
        prevChar=l;
    }
    return 1;
}

EObject* parseExpression(char* exp, unsigned char debug){
    if (!verifyExpression(exp)){
        if (debug){ printf("%s : Invalid Expression!\n", exp); }
        return NULL;
    }
    EObject* obj = (EObject*)malloc(sizeof(EObject));
    obj->exp = (char*)malloc(strlen(exp)+1);
    obj->debug = debug;
    strcpy(obj->exp, exp);
    if (obj->debug){
        printf("Parsing Expression: %s\n", obj->exp);
    }
    return obj;
}

void freeExpression(EObject* obj){
    free(obj->exp);
    free(obj);
    if (obj->debug){ printf("Freed Expression Object String!\n"); printf("Freed Expression Object!\n"); }
}
