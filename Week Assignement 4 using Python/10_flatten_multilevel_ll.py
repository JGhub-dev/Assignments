# 10. Flatten multi-level linked list (next and bottom)
class Node:
    def __init__(self,data):
        self.data=data; self.next=None; self.bottom=None

def merge(a,b):
    if not a: return b
    if not b: return a
    if a.data < b.data:
        a.bottom = merge(a.bottom, b)
        a.next = None
        return a
    else:
        b.bottom = merge(a, b.bottom)
        b.next = None
        return b

def flatten(root):
    if not root or not root.next: return root
    root.next = flatten(root.next)
    root = merge(root, root.next)
    return root

def to_list(head):
    res=[]; cur=head
    while cur:
        res.append(cur.data); cur=cur.bottom
    return res

if __name__ == "__main__":
    head = Node(5)
    head.bottom = Node(7); head.bottom.bottom = Node(8); head.bottom.bottom.bottom = Node(30)
    head.next = Node(10); head.next.bottom = Node(20)
    head.next.next = Node(19); head.next.next.bottom = Node(22); head.next.next.bottom.bottom = Node(50)
    head.next.next.next = Node(28); head.next.next.next.bottom = Node(35); head.next.next.next.bottom.bottom = Node(40); head.next.next.next.bottom.bottom.bottom = Node(45)
    flat = flatten(head)
    print(to_list(flat))
