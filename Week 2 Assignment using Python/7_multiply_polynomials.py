def multiply(A, B):
    result = [0] * (len(A) + len(B) - 1)
    for i in range(len(A)):
        for j in range(len(B)):
            result[i + j] += A[i] * B[j]
    return result
