void multiply(int A[], int B[], int m, int n, int result[]) {
    for (int i = 0; i < m + n - 1; i++)
        result[i] = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            result[i + j] += A[i] * B[j];
}
