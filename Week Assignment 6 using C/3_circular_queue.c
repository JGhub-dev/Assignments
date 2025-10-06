#include <stdio.h>
#define MAX 1000

int petrol[MAX], dist[MAX];

int tour(int n) {
    int start = 0, deficit = 0, balance = 0;
    for (int i = 0; i < n; i++) {
        balance += petrol[i] - dist[i];
        if (balance < 0) {
            start = i + 1;
            deficit += balance;
            balance = 0;
        }
    }
    return (balance + deficit >= 0) ? start : -1;
}
