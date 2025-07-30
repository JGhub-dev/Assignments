int isIdentity(int matrix[100][100], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if ((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0))
                return 0;
    return 1;
}
