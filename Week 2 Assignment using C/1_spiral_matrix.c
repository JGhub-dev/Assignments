#include <stdio.h>
#define R 100
#define C 100
void spirallyTraverse(int matrix[R][C], int r, int c) {
    int top = 0, bottom = r - 1, left = 0, right = c - 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++)
            printf("%d ", matrix[top][i]);
        top++;
        for (int i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                printf("%d ", matrix[bottom][i]);
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }
}
