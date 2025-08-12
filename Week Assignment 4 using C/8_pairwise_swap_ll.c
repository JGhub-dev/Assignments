// 8. Pairwise swap nodes of a linked list (swap data for simplicity)
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* push(struct Node* head, int data) {
    struct Node* n=(struct Node*)malloc(sizeof(struct Node)); n->data=data; n->next=head; return n;
}

struct Node* pairwiseSwap(struct Node* head) {
    struct Node* cur = head;
    while (cur && cur->next) {
        int tmp = cur->data; cur->data = cur->next->data; cur->next->data = tmp;
        cur = cur->next->next;
    }
    return head;
}

void printList(struct Node* head) {
    printf("[");
    struct Node* t=head; int first=1; while (t){ if (!first) printf(", "); printf("%d", t->data); first=0; t=t->next; } printf("]\n");
}

int main() {
    struct Node* head = NULL; head = push(head,5); head=push(head,4); head=push(head,3); head=push(head,2); head=push(head,1); // 1..5
    printList(head);
    head = pairwiseSwap(head); // expect [2,1,4,3,5]
    printList(head);
    return 0;
}
