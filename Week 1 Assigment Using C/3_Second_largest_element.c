
#include <stdio.h>
int secondLargest(int arr[], int n) {
    int max = -1, second = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i] > max) {
            second = max;
            max = arr[i];
        } else if(arr[i] > second && arr[i] != max) {
            second = arr[i];
        }
    }
    return second;
}
int main() {
    int arr[] = {10, 20, 4, 45, 99};
    printf("%d", secondLargest(arr, 5));
    return 0;
}
