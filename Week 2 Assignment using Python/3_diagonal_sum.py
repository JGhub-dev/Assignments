def diagonalSum(matrix, n):
    total = 0
    for i in range(n):
        total += matrix[i][i]
        if i != n - i - 1:
            total += matrix[i][n - i - 1]
    return total
