#include <stdio.h>
#define MAX 1000

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) { queue[++rear] = x; }
int dequeue() { return queue[front++]; }

void interleaveQueue(int n) {
    int half = n / 2;
    int first[MAX], top1 = -1;
    for (int i = 0; i < half; i++) first[++top1] = dequeue();
    for (int i = 0; i < half; i++) {
        enqueue(first[i]);
        enqueue(queue[front++]);
    }
}
