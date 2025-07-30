
#include <stdio.h>
void moveZeros(int arr[], int n) {
    int count = 0;
    for(int i = 0; i < n; i++)
        if(arr[i] != 0) arr[count++] = arr[i];
    while(count < n) arr[count++] = 0;
}
int main() {
    int arr[] = {0, 1, 0, 3, 12}, n = 5;
    moveZeros(arr, n);
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
