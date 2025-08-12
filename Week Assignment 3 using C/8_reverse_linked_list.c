// 8. Reverse linked list (iterative)
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *nxt = NULL;
    while (curr) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

void printList(struct Node* head) { while (head) { printf("%d ", head->data); head = head->next; } printf("\n"); }

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node)); head->data=1; head->next=NULL;
    head->next = (struct Node*)malloc(sizeof(struct Node)); head->next->data=2; head->next->next=NULL;
    head->next->next = (struct Node*)malloc(sizeof(struct Node)); head->next->next->data=3; head->next->next->next=NULL;
    head = reverseList(head); // expected 3 2 1
    printList(head);
    return 0;
}
