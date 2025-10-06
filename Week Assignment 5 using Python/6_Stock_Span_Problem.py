def stock_span(prices):
    n=len(prices); st=[]; span=[0]*n
    for i,p in enumerate(prices):
        while st and prices[st[-1]]<=p: st.pop()
        span[i]=i+1 if not st else i-st[-1]
        st.append(i)
    return span
if __name__=='__main__':
    import sys; d=list(map(int,sys.stdin.read().split()))
    n=d[0]; print(*stock_span(d[1:1+n]))