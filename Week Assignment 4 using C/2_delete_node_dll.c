// 2. Delete node in Doubly Linked List (delete first occurrence of key)
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; struct Node* prev; };

struct Node* push(struct Node* head, int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data; n->next = head; n->prev = NULL;
    if (head) head->prev = n;
    return n;
}

struct Node* deleteNode(struct Node* head, int key) {
    struct Node* cur = head;
    while (cur && cur->data != key) cur = cur->next;
    if (!cur) return head;
    if (cur->prev) cur->prev->next = cur->next;
    else head = cur->next;
    if (cur->next) cur->next->prev = cur->prev;
    free(cur);
    return head;
}

void printList(struct Node* head) {
    printf("[");
    struct Node* t = head; int first = 1;
    while (t) { if (!first) printf(", "); printf("%d", t->data); first=0; t = t->next; }
    printf("]\n");
}

int main() {
    struct Node* head = NULL;
    head = push(head, 5); head = push(head, 4); head = push(head, 3); head = push(head, 2); head = push(head,1); // 1..5
    printList(head);
    head = deleteNode(head, 3); // remove 3: [1,2,4,5]
    printList(head);
    head = deleteNode(head, 1); // remove head: [2,4,5]
    printList(head);
    head = deleteNode(head, 10); // no-op
    printList(head);
    return 0;
}
