
#include <stdio.h>
int findLargest(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > max) max = arr[i];
    return max;
}
int main() {
    int arr[] = {1, 3, 5, 2};
    printf("%d", findLargest(arr, 4));
    return 0;
}
