#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct { int *arr; int top; int capacity; } Stack;
Stack* createStack(int cap){ Stack* s=malloc(sizeof(Stack)); s->capacity=cap; s->top=-1; s->arr=malloc(sizeof(int)*cap); return s; }
int isEmpty(Stack* s){return s->top==-1;} int isFull(Stack* s){return s->top==s->capacity-1;}
void push(Stack* s,int x){ if(isFull(s)){printf("Overflow\n");return;} s->arr[++s->top]=x; }
int pop(Stack* s){ if(isEmpty(s)){printf("Underflow\n");return INT_MIN;} return s->arr[s->top--]; }
int peek(Stack* s){ if(isEmpty(s))return INT_MIN; return s->arr[s->top]; }
int main(){ Stack* s=createStack(100); push(s,10); push(s,20); printf("%d\n",peek(s)); printf("%d\n",pop(s)); return 0; }