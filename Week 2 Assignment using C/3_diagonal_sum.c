int diagonalSum(int matrix[100][100], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];
        if (i != n - i - 1)
            sum += matrix[i][n - i - 1];
    }
    return sum;
}
