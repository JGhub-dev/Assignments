// 9. Add two numbers represented by linked lists (digits in reverse order)
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* newNode(int d) { struct Node* n = (struct Node*)malloc(sizeof(struct Node)); n->data=d; n->next=NULL; return n; }

struct Node* addTwoLists(struct Node* l1, struct Node* l2) {
    struct Node dummy; dummy.next = NULL;
    struct Node* tail = &dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
        int sum = carry + (l1?l1->data:0) + (l2?l2->data:0);
        carry = sum/10;
        tail->next = newNode(sum%10);
        tail = tail->next;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    return dummy.next;
}

void printList(struct Node* head) { while (head) { printf("%d ", head->data); head = head->next; } printf("\n"); }

int main() {
    // 243 -> represented as 3->4->2
    struct Node* a = newNode(3); a->next = newNode(4); a->next->next = newNode(2);
    // 564 -> 4->6->5
    struct Node* b = newNode(4); b->next = newNode(6); b->next->next = newNode(5);
    struct Node* res = addTwoLists(a, b); // expected 7 0 8 -> 807
    printList(res);
    return 0;
}
