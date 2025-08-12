# 6. Detect loop (Floyd)
class Node:
    def __init__(self,data):
        self.data=data; self.next=None

def detectLoop(head):
    slow = head; fast = head
    while fast and fast.next:
        slow = slow.next; fast = fast.next.next
        if slow == fast: return True
    return False

if __name__ == "__main__":
    a = Node(1); b = Node(2); c = Node(3)
    a.next = b; b.next = c; c.next = b
    print(detectLoop(a))
    c.next = None
    print(detectLoop(a))
