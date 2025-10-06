#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 256

int countAtMostK(char *s, int k) {
    int freq[MAX] = {0}, distinct = 0, res = 0;
    int left = 0;
    for (int right = 0; s[right]; right++) {
        if (freq[s[right]] == 0) distinct++;
        freq[s[right]]++;
        while (distinct > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) distinct--;
            left++;
        }
        res += right - left + 1;
    }
    return res;
}
int countExactlyK(char *s, int k) {
    return countAtMostK(s, k) - countAtMostK(s, k - 1);
}
int main() {
    char s[1000]; int k;
    scanf("%s %d", s, &k);
    printf("%d", countExactlyK(s, k));
    return 0;
}