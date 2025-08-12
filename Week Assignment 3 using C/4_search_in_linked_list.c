// 4. Search in linked list - return boolean (1 if found else 0)
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

int searchList(struct Node* head, int key) {
    while (head) {
        if (head->data == key) return 1;
        head = head->next;
    }
    return 0;
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node)); head->data=5; head->next=NULL;
    head->next = (struct Node*)malloc(sizeof(struct Node)); head->next->data=10; head->next->next=NULL;
    printf("%d\n", searchList(head, 10)); // 1
    printf("%d\n", searchList(head, 7)); // 0
    return 0;
}
