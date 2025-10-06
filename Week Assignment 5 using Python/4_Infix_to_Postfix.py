def infix_to_postfix(expr):
    def prec(c): return {'^':3,'*':2,'/':2,'+':1,'-':1}.get(c,0)
    out=[]; st=[]; i=0; n=len(expr)
    while i<n:
        if expr[i].isspace(): i+=1; continue
        if expr[i].isalnum():
            j=i
            while j<n and expr[j].isalnum(): j+=1
            out.append(expr[i:j]); i=j
        elif expr[i]=='(':
            st.append('('); i+=1
        elif expr[i]==')':
            while st and st[-1]!='(': out.append(st.pop())
            if st and st[-1]=='(': st.pop(); i+=1
        else:
            op=expr[i]; i+=1
            while st and st[-1]!='(' and ((prec(st[-1])>prec(op)) or (prec(st[-1])==prec(op) and op!='^')):
                out.append(st.pop())
            st.append(op)
    while st: out.append(st.pop())
    return ' '.join(out)
if __name__=='__main__':
    import sys; print(infix_to_postfix(sys.stdin.readline().strip()))