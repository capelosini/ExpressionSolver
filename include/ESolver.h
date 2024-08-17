#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct EObject EObject;
struct EObject{
    char* exp;
    unsigned char debug;
};

unsigned char verifyExpression(char* exp);
EObject* parseExpression(char* exp, unsigned char debug);
void freeExpression(EObject* obj);
