#include <stdio.h>
#define MAX 1000

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void push1(int x) { stack1[++top1] = x; }
int pop1() { return stack1[top1--]; }
void push2(int x) { stack2[++top2] = x; }
int pop2() { return stack2[top2--]; }

void enqueue(int x) { push1(x); }

int dequeue() {
    if (top1 == -1 && top2 == -1) return -1;
    if (top2 == -1)
        while (top1 != -1) push2(pop1());
    return pop2();
}
