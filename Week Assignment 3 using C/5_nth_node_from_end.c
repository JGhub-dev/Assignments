// 5. Nth node from end (two-pointer)
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

int getNthFromEnd(struct Node* head, int n) {
    struct Node *fast = head, *slow = head;
    for (int i=0;i<n;i++) {
        if (!fast) return -1; // list shorter than n
        fast = fast->next;
    }
    while (fast) { fast = fast->next; slow = slow->next; }
    return slow ? slow->data : -1;
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node)); head->data=1; head->next=NULL;
    head->next = (struct Node*)malloc(sizeof(struct Node)); head->next->data=2; head->next->next=NULL;
    head->next->next = (struct Node*)malloc(sizeof(struct Node)); head->next->next->data=3; head->next->next->next=NULL;
    printf("%d\n", getNthFromEnd(head, 1)); // 3
    printf("%d\n", getNthFromEnd(head, 3)); // 1
    printf("%d\n", getNthFromEnd(head, 4)); // -1
    return 0;
}
