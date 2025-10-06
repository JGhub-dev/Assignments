#include <stdio.h>
#define MAX 1000

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) { queue[++rear] = x; }
int dequeue() { return queue[front++]; }

void reverseFirstK(int k) {
    int stack[MAX], top = -1;
    for (int i = 0; i < k; i++) stack[++top] = dequeue();
    while (top != -1) enqueue(stack[top--]);
}
