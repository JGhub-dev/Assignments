// 10. Hackerrank: Print elements of linked list
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

void display(struct Node* head) {
    while (head) {
        printf("%d\n", head->data);
        head = head->next;
    }
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node)); head->data=1; head->next=NULL;
    head->next = (struct Node*)malloc(sizeof(struct Node)); head->next->data=2; head->next->next=NULL;
    head->next->next = (struct Node*)malloc(sizeof(struct Node)); head->next->next->data=3; head->next->next->next=NULL;
    display(head);
    return 0;
}
