def main():
    import sys
    q=int(sys.stdin.readline()); s=''; st=[]
    for _ in range(q):
        p=sys.stdin.readline().split(); t=int(p[0])
        if t==1: st.append(s); s+=p[1]
        elif t==2: st.append(s); s=s[:-int(p[1])]
        elif t==3: print(s[int(p[1])-1])
        elif t==4: s=st.pop()
if __name__=='__main__': main()