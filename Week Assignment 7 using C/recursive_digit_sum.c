#include <stdio.h>
#include <string.h>

int digitSum(char *n) {
    if (strlen(n) == 1) return n[0] - '0';
    long long sum = 0;
    for (int i = 0; n[i]; i++) sum += n[i] - '0';
    char temp[20];
    sprintf(temp, "%lld", sum);
    return digitSum(temp);
}
int main() {
    char n[1000]; int k;
    scanf("%s %d", n, &k);
    char big[100000] = "";
    for (int i = 0; i < k; i++) strcat(big, n);
    printf("%d", digitSum(big));
    return 0;
}