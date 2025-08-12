// 1. Insert at beginning / Insert in sorted DLL (GFG style)
// We'll implement insertInSorted for a doubly linked list and also provide insertAtBeginning demo.
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; struct Node* prev; };

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data; node->next = head; node->prev = NULL;
    if (head) head->prev = node;
    return node;
}

// Insert in sorted DLL (ascending)
struct Node* sortedInsert(struct Node* head, int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data; node->next = node->prev = NULL;
    if (!head) return node;
    struct Node* cur = head;
    // insert at beginning
    if (data <= head->data) {
        node->next = head; head->prev = node; return node;
    }
    while (cur->next && cur->next->data < data) cur = cur->next;
    node->next = cur->next;
    if (cur->next) cur->next->prev = node;
    cur->next = node; node->prev = cur;
    return head;
}

void printListAsc(struct Node* head) {
    printf("[");
    struct Node* t = head; int first = 1;
    while (t) {
        if (!first) printf(", "); printf("%d", t->data); first = 0;
        t = t->next;
    }
    printf("]\n");
}

int main() {
    struct Node* head = NULL;
    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10); // list: 10,20,30
    printListAsc(head);
    head = sortedInsert(head, 25); // expect [10, 20, 25, 30]
    printListAsc(head);
    head = sortedInsert(head, 5); // expect [5, 10, 20, 25, 30]
    printListAsc(head);
    return 0;
}
