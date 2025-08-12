# 5. Nth node from end (two-pointer)
class Node:
    def __init__(self,data):
        self.data=data; self.next=None

def getNthFromEnd(head, n):
    fast = head
    for _ in range(n):
        if not fast: return -1
        fast = fast.next
    slow = head
    while fast:
        fast = fast.next; slow = slow.next
    return slow.data if slow else -1

if __name__ == "__main__":
    head = Node(1); head.next = Node(2); head.next.next = Node(3)
    print(getNthFromEnd(head,1))
    print(getNthFromEnd(head,3))
    print(getNthFromEnd(head,4))
