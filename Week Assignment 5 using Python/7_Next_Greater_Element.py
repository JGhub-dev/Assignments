def next_greater(arr):
    n=len(arr); res=[-1]*n; st=[]
    for i in range(n-1,-1,-1):
        while st and st[-1]<=arr[i]: st.pop()
        res[i]=-1 if not st else st[-1]
        st.append(arr[i])
    return res
if __name__=='__main__':
    import sys; d=list(map(int,sys.stdin.read().split()))
    n=d[0]; print(*next_greater(d[1:1+n]))