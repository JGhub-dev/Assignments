#include <stdio.h>
#define MAX 1000
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

void dequeue() {
    if (front == -1 || front > rear) return;
    front++;
}

int frontElement() {
    if (front == -1 || front > rear) return -1;
    return queue[front];
}
