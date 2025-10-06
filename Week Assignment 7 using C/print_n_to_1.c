#include <stdio.h>
void printNos(int N) {
    if (N == 0) return;
    printf("%d ", N);
    printNos(N - 1);
}
int main() {
    int N;
    scanf("%d", &N);
    printNos(N);
    return 0;
}