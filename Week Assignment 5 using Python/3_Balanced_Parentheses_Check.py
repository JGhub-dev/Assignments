def balanced(s):
    st=[]; pairs={')':'(',']':'[','}':'{'}
    for c in s:
        if c in '([{': st.append(c)
        elif c in ')]}':
            if not st or st[-1]!=pairs[c]: return False
            st.pop()
    return not st
if __name__=='__main__':
    import sys; s=sys.stdin.readline().strip()
    print('YES' if balanced(s) else 'NO')