class Node:
    def __init__(self,v,nxt=None): self.v=v; self.next=nxt
class LinkedStack:
    def __init__(self): self.head=None
    def push(self,x): self.head=Node(x,self.head)
    def pop(self):
        if not self.head: raise IndexError
        v=self.head.v; self.head=self.head.next; return v
    def peek(self): return None if not self.head else self.head.v
if __name__=='__main__': s=LinkedStack(); s.push(10); s.push(20); print(s.peek()); print(s.pop())