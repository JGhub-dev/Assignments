def isSparse(matrix):
    total = len(matrix) * len(matrix[0])
    count = sum(row.count(0) for row in matrix)
    return count > total // 2
