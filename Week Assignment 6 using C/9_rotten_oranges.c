#include <stdio.h>
#define MAX 100

int orangesRotting(int grid[MAX][MAX], int r, int c) {
    int queue[MAX*MAX][2], front = 0, rear = 0, count = 0, time = 0;
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (grid[i][j] == 2) {
                queue[rear][0] = i; queue[rear++][1] = j;
            }
    while (front < rear) {
        int size = rear - front;
        int flag = 0;
        for (int i = 0; i < size; i++) {
            int x = queue[front][0], y = queue[front++][1];
            for (int d = 0; d < 4; d++) {
                int nx = x + dirs[d][0], ny = y + dirs[d][1];
                if (nx>=0 && ny>=0 && nx<r && ny<c && grid[nx][ny]==1) {
                    grid[nx][ny]=2;
                    queue[rear][0]=nx; queue[rear++][1]=ny;
                    flag=1;
                }
            }
        }
        if (flag) time++;
    }
    for (int i=0;i<r;i++) for (int j=0;j<c;j++) if (grid[i][j]==1) return -1;
    return time;
}
