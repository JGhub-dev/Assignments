# 7. Check if linked list is circular
class Node:
    def __init__(self,data):
        self.data=data; self.next=None

def is_circular(head):
    if not head: return True
    cur = head.next
    while cur and cur != head: cur = cur.next
    return cur == head

if __name__ == "__main__":
    a = Node(1); b = Node(2); a.next = b; b.next = a
    print(is_circular(a))
    b.next = None
    print(is_circular(a))
