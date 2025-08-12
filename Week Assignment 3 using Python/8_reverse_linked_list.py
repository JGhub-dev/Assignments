# 8. Reverse linked list (iterative)
class Node:
    def __init__(self,data):
        self.data=data; self.next=None

def reverseList(head):
    prev = None; curr = head
    while curr:
        nxt = curr.next
        curr.next = prev
        prev = curr
        curr = nxt
    return prev

if __name__ == "__main__":
    head = Node(1); head.next = Node(2); head.next.next = Node(3)
    head = reverseList(head)
    t = head
    while t:
        print(t.data, end=" ")
        t = t.next
    print()
