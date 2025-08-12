// 1. Linked list insertion - GFG style (insert at end)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data; newNode->next = NULL;
    if (!head) return newNode;
    struct Node* t = head;
    while (t->next) t = t->next;
    t->next = newNode;
    return head;
}

// helper to print
void printList(struct Node* head) {
    while (head) { printf("%d ", head->data); head = head->next; }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    printList(head); // expected 10 20 30
    return 0;
}
