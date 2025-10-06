#include <stdio.h>
long long power(int base, int exp) {
    if (exp == 0) return 1;
    return base * power(base, exp - 1);
}
int main() {
    int n, r;
    scanf("%d %d", &n, &r);
    printf("%lld", power(n, r));
    return 0;
}