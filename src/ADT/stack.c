// Implementasi stack

#include "boolean.h"
#include "stack.h"
#include <stdio.h>

void CreateEmpty(Stack *S) {
 S->TOP = StackNil;
}

boolean IsEmpty(Stack S) {
 return (Top(S) == StackNil);
}

boolean IsFull(Stack S) {
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