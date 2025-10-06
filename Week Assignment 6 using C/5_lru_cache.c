#include <stdio.h>
#include <stdlib.h>

// Simple LRU Cache using DLL + Hash (concept only)

#define MAX 1000

struct Node {
    int key, value;
    struct Node *prev, *next;
};

struct Node* head = NULL;
struct Node* tail = NULL;
int count = 0, capacity = 0;

void moveToFront(struct Node* node) {
    if (node == head) return;
    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;
    if (node == tail) tail = tail->prev;
    node->next = head;
    node->prev = NULL;
    if (head) head->prev = node;
    head = node;
    if (!tail) tail = node;
}
