// 3. Reverse a Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; struct Node* prev; };

struct Node* push(struct Node* head, int data) {
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->data=data; n->next=head; n->prev=NULL;
    if (head) head->prev = n;
    return n;
}

struct Node* reverseDLL(struct Node* head) {
    struct Node* cur = head;
    struct Node* temp = NULL;
    while (cur) {
        // swap next and prev
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        head = cur; // update head to current
        cur = cur->prev; // moved forward using old next
    }
    return head;
}

void printList(struct Node* head) {
    printf("[");
    struct Node* t=head; int first=1;
    while (t) { if (!first) printf(", "); printf("%d", t->data); first=0; t=t->next; }
    printf("]\n");
}

int main() {
    struct Node* head = NULL;
    head = push(head, 3); head = push(head, 2); head = push(head, 1); // 1,2,3
    printList(head);
    head = reverseDLL(head); // 3,2,1
    printList(head);
    return 0;
}
