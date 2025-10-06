def super_digit(n):
    if len(n) == 1:
        return int(n)
    s = sum(int(d) for d in n)
    return super_digit(str(s))

n, k = input().split()
n = n * int(k)
print(super_digit(n))