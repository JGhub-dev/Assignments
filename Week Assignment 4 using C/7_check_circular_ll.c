// 7. Check if linked list is circular (returns 1 if circular else 0)
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

int isCircular(struct Node* head) {
    if (!head) return 1; // empty list is considered circular per many definitions
    struct Node* cur = head->next;
    while (cur && cur != head) cur = cur->next;
    return cur == head;
}

int main() {
    struct Node* a = (struct Node*)malloc(sizeof(struct Node)); a->data=1; a->next=NULL;
    struct Node* b = (struct Node*)malloc(sizeof(struct Node)); b->data=2; b->next=NULL;
    a->next = b; b->next = a; // circular
    printf("%d\n", isCircular(a)); // 1
    b->next = NULL;
    printf("%d\n", isCircular(a)); // 0
    return 0;
}
