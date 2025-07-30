int isSparse(int matrix[100][100], int r, int c) {
    int count = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (matrix[i][j] == 0)
                count++;
    return (count > (r * c) / 2);
}
