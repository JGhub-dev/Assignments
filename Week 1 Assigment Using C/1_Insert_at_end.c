
#include <stdio.h>
void insertAtEnd(int arr[], int n, int x) {
    arr[n] = x;
}
int main() {
    int arr[100] = {1, 2, 3}, n = 3, x = 4;
    insertAtEnd(arr, n, x);
    for(int i = 0; i <= n; i++) printf("%d ", arr[i]);
    return 0;
}
