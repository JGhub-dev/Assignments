// 6. Detect loop in linked list (Floyd's cycle-finding)
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

int detectLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next; fast = fast->next->next;
        if (slow == fast) return 1;
    }
    return 0;
}

int main() {
    struct Node* a = (struct Node*)malloc(sizeof(struct Node)); a->data=1;
    struct Node* b = (struct Node*)malloc(sizeof(struct Node)); b->data=2;
    struct Node* c = (struct Node*)malloc(sizeof(struct Node)); c->data=3;
    a->next=b; b->next=c; c->next=b; // loop
    printf("%d\n", detectLoop(a)); // 1
    c->next = NULL;
    printf("%d\n", detectLoop(a)); // 0 (after break)
    return 0;
}
