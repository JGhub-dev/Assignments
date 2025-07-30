def countZeros(matrix, n):
    count = 0
    for row in matrix:
        for val in reversed(row):
            if val == 0:
                count += 1
            else:
                break
    return count
