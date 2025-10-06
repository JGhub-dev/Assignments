#include <stdio.h>
#include <stdlib.h>
typedef struct Node{int val;struct Node*next;}Node;
typedef struct{Node*head;}Stack;
Stack*createStack(){Stack*s=malloc(sizeof(Stack));s->head=NULL;return s;}
int isEmpty(Stack*s){return s->head==NULL;}
void push(Stack*s,int x){Node*n=malloc(sizeof(Node));n->val=x;n->next=s->head;s->head=n;}
int pop(Stack*s){if(isEmpty(s)){printf("Underflow\n");return -1;}Node*t=s->head;int v=t->val;s->head=t->next;free(t);return v;}
int peek(Stack*s){return isEmpty(s)?-1:s->head->val;}
int main(){Stack*s=createStack();push(s,1);push(s,2);printf("%d\n",peek(s));printf("%d\n",pop(s));return 0;}