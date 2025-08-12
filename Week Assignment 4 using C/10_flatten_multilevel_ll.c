// 10. Flattening a linked list where each node has next and bottom pointers
// We'll implement the GFG style: each node has 'data' and 'next' and 'bottom'. We flatten by merging sorted lists.
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; struct Node* bottom; };

struct Node* merge(struct Node* a, struct Node* b) {
    if (!a) return b;
    if (!b) return a;
    struct Node* result = NULL;
    if (a->data < b->data) {
        result = a; result->bottom = merge(a->bottom, b);
    } else {
        result = b; result->bottom = merge(a, b->bottom);
    }
    result->next = NULL;
    return result;
}

struct Node* flatten(struct Node* root) {
    if (!root || !root->next) return root;
    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;
}

void printBottomList(struct Node* head) {
    printf("[");
    struct Node* t=head; int first=1;
    while (t) { if (!first) printf(", "); printf("%d", t->data); first=0; t = t->bottom; }
    printf("]\n");
}

struct Node* newNode(int d) { struct Node* n=(struct Node*)malloc(sizeof(struct Node)); n->data=d; n->next=NULL; n->bottom=NULL; return n; }

int main() {
    // Create example:
    // 5 -> 10 -> 19 -> 28
    // |     |     |     |
    // V     V     V     V
    // 7     20    22    35
    // |           |     |
    // V           V     V
    // 8           50    40
    // |                 |
    // V                 V
    // 30                45
    struct Node* head = newNode(5);
    head->bottom = newNode(7); head->bottom->bottom = newNode(8); head->bottom->bottom->bottom = newNode(30);
    head->next = newNode(10); head->next->bottom = newNode(20);
    head->next->next = newNode(19); head->next->next->bottom = newNode(22); head->next->next->bottom->bottom = newNode(50);
    head->next->next->next = newNode(28); head->next->next->next->bottom = newNode(35); head->next->next->next->bottom->bottom = newNode(40); head->next->next->next->bottom->bottom->bottom = newNode(45);
    struct Node* flat = flatten(head);
    printBottomList(flat); // expect flattened sorted list
    return 0;
}
