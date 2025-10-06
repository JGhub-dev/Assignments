def printNos(N):
    if N == 0:
        return
    print(N, end=' ')
    printNos(N - 1)

N = int(input())
printNos(N)