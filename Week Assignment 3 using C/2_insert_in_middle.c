// 2. Insert in middle of linked list
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* insertInMiddle(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data; newNode->next = NULL;
    if (!head) return newNode;
    // find middle (for even length, insert after n/2 nodes)
    struct Node *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // insert after slow
    newNode->next = slow->next;
    slow->next = newNode;
    return head;
}

void printList(struct Node* head) { while (head) { printf("%d ", head->data); head = head->next; } printf("\n"); }

int main() {
    struct Node* head = NULL;
    // create list 1->2->4->5
    head = (struct Node*)malloc(sizeof(struct Node)); head->data=1; head->next=NULL;
    head->next = (struct Node*)malloc(sizeof(struct Node)); head->next->data=2; head->next->next=NULL;
    head->next->next = (struct Node*)malloc(sizeof(struct Node)); head->next->next->data=4; head->next->next->next=NULL;
    head->next->next->next = (struct Node*)malloc(sizeof(struct Node)); head->next->next->next->data=5; head->next->next->next->next=NULL;
    head = insertInMiddle(head, 3); // expected 1 2 3 4 5
    printList(head);
    return 0;
}
