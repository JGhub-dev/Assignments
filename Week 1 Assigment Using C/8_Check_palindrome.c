
#include <stdio.h>
#include <string.h>
int isPalindrome(char str[]) {
    int l = 0, r = strlen(str) - 1;
    while(l < r) {
        if(str[l] != str[r]) return 0;
        l++; r--;
    }
    return 1;
}
int main() {
    char str[] = "madam";
    printf("%s", isPalindrome(str) ? "Yes" : "No");
    return 0;
}
