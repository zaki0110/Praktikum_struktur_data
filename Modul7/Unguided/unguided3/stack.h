#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int maxElement = 20;
typedef int infotype;

struct Stack {
    infotype info[maxElement];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
void pushAscending(Stack &S, int x);
void getInputStream(Stack &S);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
