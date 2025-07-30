void transpose(int A[100][100], int r, int c, int B[100][100]) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            B[j][i] = A[i][j];
}
