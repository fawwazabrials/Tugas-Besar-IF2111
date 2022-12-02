// Implementasi stack

#include "stack.h"
#include <stdio.h>

void CreateEmptyStack(Stack *S) {
 S->TOP = StackNil;
}

boolean IsEmptyStack(Stack S) {
 return (Top(S) == StackNil);
}

boolean IsFullStack(Stack S) {
 return (Top(S)+1 == StackMaxEl);
}

void Push(Stack * S, int X) {
 S->TOP++;
 InfoTop(*S) = X;
}

void Pop(Stack * S, int* X) {
 *X = InfoTop(*S);
 S->TOP--;
}


//int main () {}