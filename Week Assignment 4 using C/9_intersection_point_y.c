// 9. Intersection point in Y shaped linked list
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

int getCount(struct Node* head) { int c=0; while (head) { c++; head=head->next; } return c; }

int getIntersectionNode(struct Node* head1, struct Node* head2) {
    int c1 = getCount(head1), c2 = getCount(head2);
    struct Node *p1=head1, *p2=head2;
    int d;
    if (c1 > c2) { d = c1 - c2; while (d--) p1 = p1->next; }
    else { d = c2 - c1; while (d--) p2 = p2->next; }
    while (p1 && p2) {
        if (p1 == p2) return p1->data;
        p1 = p1->next; p2 = p2->next;
    }
    return -1;
}

int main() {
    // create intersection: 1->2->3\
    //                      6->7 -> 9 -> NULL
    struct Node* common = (struct Node*)malloc(sizeof(struct Node)); common->data=9; common->next=NULL;
    struct Node* a = (struct Node*)malloc(sizeof(struct Node)); a->data=3; a->next=common;
    struct Node* b = (struct Node*)malloc(sizeof(struct Node)); b->data=2; b->next=a;
    struct Node* c = (struct Node*)malloc(sizeof(struct Node)); c->data=1; c->next=b; // head1 = c (1->2->3->9)
    struct Node* x = (struct Node*)malloc(sizeof(struct Node)); x->data=6; x->next=(struct Node*)malloc(sizeof(struct Node));
    x->next->data=7; x->next->next = common; // head2 = x (6->7->9)
    printf("%d\n", getIntersectionNode(c, x)); // expect 9
    return 0;
}
