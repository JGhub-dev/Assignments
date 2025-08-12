// 6. Sorted insert for Circular Linked List (maintain sorted order)
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* sortedInsertCLL(struct Node* head, int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node)); n->data = data; n->next = n;
    if (!head) return n;
    struct Node *cur = head, *minNode = head;
    // handle insertion where data is smallest or largest that wraps around
    do {
        if (cur->data <= data && cur->next->data >= data) {
            // insert between cur and cur->next
            n->next = cur->next; cur->next = n; return head;
        }
        cur = cur->next;
        if (cur->data < minNode->data) minNode = cur;
    } while (cur != head);
    // didn't find a middle spot: insert after max (i.e., before minNode)
    // find max node
    cur = minNode;
    while (cur->next != minNode) cur = cur->next;
    n->next = minNode; cur->next = n;
    // if new data is smaller than head, make it new head
    if (data < head->data) return n;
    return head;
}

void printCLL(struct Node* head) {
    if (!head) { printf("[]\n"); return; }
    printf("[");
    struct Node* cur = head; int first=1;
    do { if (!first) printf(", "); printf("%d", cur->data); first=0; cur=cur->next; } while (cur!=head);
    printf("]\n");
}

int main() {
    struct Node* head = NULL;
    head = sortedInsertCLL(head, 20);
    head = sortedInsertCLL(head, 10);
    head = sortedInsertCLL(head, 30);
    head = sortedInsertCLL(head, 25);
    printCLL(head); // expect [10,20,25,30]
    return 0;
}
