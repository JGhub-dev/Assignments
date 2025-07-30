
#include <stdio.h>
int main() {
    int arr[] = {1, 2, 2, 3, 3, 3}, freq[101] = {0};
    int n = 6;
    for(int i = 0; i < n; i++) freq[arr[i]]++;
    for(int i = 0; i < 101; i++)
        if(freq[i]) printf("%d occurs %d times\n", i, freq[i]);
    return 0;
}
