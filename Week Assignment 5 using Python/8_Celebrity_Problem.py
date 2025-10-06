def celebrity(M):
    n=len(M); a,b=0,n-1
    while a<b:
        if M[a][b]: a+=1
        else: b-=1
    c=a
    for i in range(n):
        if i==c: continue
        if M[c][i] or not M[i][c]: return -1
    return c
if __name__=='__main__':
    import sys; d=list(map(int,sys.stdin.read().split()))
    n=d[0]; arr=d[1:]; M=[arr[i*n:(i+1)*n] for i in range(n)]
    print(celebrity(M))