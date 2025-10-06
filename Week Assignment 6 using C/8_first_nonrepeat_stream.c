#include <stdio.h>
#define MAX 256

void firstNonRepeating(char stream[], int n) {
    int freq[MAX] = {0};
    for (int i = 0; i < n; i++) {
        freq[(int)stream[i]]++;
        char res = '#';
        for (int j = 0; j <= i; j++) {
            if (freq[(int)stream[j]] == 1) { res = stream[j]; break; }
        }
    }
}
