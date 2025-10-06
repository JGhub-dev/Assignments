def min_rev(s):
    n=len(s); 
    if n%2: return -1
    st=[]
    for c in s:
        if c=='{': st.append(c)
        elif st and st[-1]=='{': st.pop()
        else: st.append('}')
    open_=0
    while st and st[-1]=='{': open_+=1; st.pop()
    close=len(st)
    return (open_+1)//2+(close+1)//2
if __name__=='__main__':
    import sys; print(min_rev(sys.stdin.readline().strip()))