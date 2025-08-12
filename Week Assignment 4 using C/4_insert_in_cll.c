// 4. Insert in Circular Linked List (insert after a given node value or sorted insert demo)
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* insertAfter(struct Node* head, int afterVal, int data) {
    if (!head) {
        struct Node* n = (struct Node*)malloc(sizeof(struct Node));
        n->data = data; n->next = n;
        return n;
    }
    struct Node* cur = head;
    // find node with value afterVal; if not found, insert after head
    do {
        if (cur->data == afterVal) break;
        cur = cur->next;
    } while (cur != head);
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data; n->next = cur->next; cur->next = n;
    return head;
}

void printCLL(struct Node* head) {
    if (!head) { printf("[]\n"); return; }
    printf("[");
    struct Node* cur = head; int first=1;
    do {
        if (!first) printf(", "); printf("%d", cur->data); first=0;
        cur = cur->next;
    } while (cur != head);
    printf("]\n");
}

int main() {
    struct Node* head = NULL;
    head = insertAfter(head, 0, 10); // creates single node list [10]
    printCLL(head);
    head = insertAfter(head, 10, 20); // [10,20]
    head = insertAfter(head, 20, 30); // [10,20,30]
    printCLL(head);
    head = insertAfter(head, 20, 25); // insert after 20 -> [10,20,25,30]
    printCLL(head);
    return 0;
}
