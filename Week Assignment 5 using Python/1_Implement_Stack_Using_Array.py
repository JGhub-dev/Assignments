class Stack:
    def __init__(self,cap=100): self.data=[]; self.cap=cap
    def push(self,x): 
        if len(self.data)==self.cap: raise OverflowError
        self.data.append(x)
    def pop(self): return self.data.pop()
    def peek(self): return self.data[-1] if self.data else None
if __name__=='__main__': s=Stack(); s.push(1); s.push(2); print(s.peek()); print(s.pop())