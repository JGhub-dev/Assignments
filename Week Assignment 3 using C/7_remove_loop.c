// 7. Remove loop from linked list (Floyd + find start)
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

void removeLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;
    int found = 0;
    while (fast && fast->next) {
        slow = slow->next; fast = fast->next->next;
        if (slow == fast) { found = 1; break; }
    }
    if (!found) return;
    slow = head;
    if (slow == fast) {
        // loop starts at head: find last node
        while (fast->next != slow) fast = fast->next;
        fast->next = NULL;
        return;
    }
    while (slow->next != fast->next) {
        slow = slow->next; fast = fast->next;
    }
    fast->next = NULL;
}

int detectLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast && fast->next) { slow = slow->next; fast = fast->next->next; if (slow==fast) return 1; }
    return 0;
}

int main() {
    struct Node* a = (struct Node*)malloc(sizeof(struct Node)); a->data=1;
    struct Node* b = (struct Node*)malloc(sizeof(struct Node)); b->data=2;
    struct Node* c = (struct Node*)malloc(sizeof(struct Node)); c->data=3;
    a->next=b; b->next=c; c->next=b; // loop
    printf("Before: %d\n", detectLoop(a)); // 1
    removeLoop(a);
    printf("After: %d\n", detectLoop(a)); // 0
    return 0;
}
