// 5. Josephus Problem (GFG classic)
#include <stdio.h>
#include <stdlib.h>

// Recursive solution for Josephus (1-based indexing)
int josephus(int n, int k) {
    if (n == 1) return 1;
    return (josephus(n-1, k) + k - 1) % n + 1;
}

int main() {
    printf("%d\n", josephus(7, 3)); // expected 4 (for n=7,k=3)
    printf("%d\n", josephus(5, 2)); // expected 3
    return 0;
}
