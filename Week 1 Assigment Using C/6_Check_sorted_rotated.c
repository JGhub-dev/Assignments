
#include <stdio.h>
int isSortedAndRotated(int arr[], int n) {
    int count = 0;
    for(int i = 0; i < n; i++)
        if(arr[i] > arr[(i+1)%n]) count++;
    return (count <= 1);
}
int main() {
    int arr[] = {3, 4, 5, 1, 2}, n = 5;
    printf("%s", isSortedAndRotated(arr, n) ? "Yes" : "No");
    return 0;
}
