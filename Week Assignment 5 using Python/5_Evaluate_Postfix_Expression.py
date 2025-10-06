def eval_postfix(expr):
    st=[]
    for t in expr.split():
        if t.lstrip('-').isdigit(): st.append(int(t))
        else:
            b=st.pop(); a=st.pop()
            if t=='+': st.append(a+b)
            elif t=='-': st.append(a-b)
            elif t=='*': st.append(a*b)
            elif t=='/': st.append(int(a/b))
    return st[-1]
if __name__=='__main__':
    import sys; print(eval_postfix(sys.stdin.readline().strip()))