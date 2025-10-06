def power(N, R):
    if R == 0:
        return 1
    return N * power(N, R - 1)

N, R = map(int, input().split())
print(power(N, R))