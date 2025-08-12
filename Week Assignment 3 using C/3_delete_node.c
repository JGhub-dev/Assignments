// 3. Delete a node in single linked list (delete first occurrence of key)
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* deleteNode(struct Node* head, int key) {
    if (!head) return NULL;
    struct Node* temp = head;
    if (head->data == key) {
        struct Node* nxt = head->next;
        free(head);
        return nxt;
    }
    while (temp->next && temp->next->data != key) temp = temp->next;
    if (temp->next) {
        struct Node* todel = temp->next;
        temp->next = todel->next;
        free(todel);
    }
    return head;
}

void printList(struct Node* head) { while (head) { printf("%d ", head->data); head = head->next; } printf("\n"); }

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node)); head->data=1; head->next=NULL;
    head->next = (struct Node*)malloc(sizeof(struct Node)); head->next->data=2; head->next->next=NULL;
    head->next->next = (struct Node*)malloc(sizeof(struct Node)); head->next->next->data=3; head->next->next->next=NULL;
    head = deleteNode(head, 2); // expected 1 3
    printList(head);
    head = deleteNode(head, 1); // expected 3
    printList(head);
    return 0;
}
