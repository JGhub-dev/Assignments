struct Node {
    int coeff;
    int pow;
    struct Node* next;
};
struct Node* addPolynomial(struct Node* p1, struct Node* p2) {
    struct Node* res = NULL, **lastPtrRef = &res;
    while (p1 && p2) {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        if (p1->pow > p2->pow) {
            temp->coeff = p1->coeff;
            temp->pow = p1->pow;
            p1 = p1->next;
        } else if (p1->pow < p2->pow) {
            temp->coeff = p2->coeff;
            temp->pow = p2->pow;
            p2 = p2->next;
        } else {
            temp->coeff = p1->coeff + p2->coeff;
            temp->pow = p1->pow;
            p1 = p1->next;
            p2 = p2->next;
        }
        temp->next = NULL;
        *lastPtrRef = temp;
        lastPtrRef = &(temp->next);
    }
    *lastPtrRef = (p1) ? p1 : p2;
    return res;
}
