# 7. Remove loop from linked list
class Node:
    def __init__(self,data):
        self.data=data; self.next=None

def removeLoop(head):
    slow = head; fast = head; found = False
    while fast and fast.next:
        slow = slow.next; fast = fast.next.next
        if slow == fast:
            found = True; break
    if not found: return
    slow = head
    if slow == fast:
        # find last node
        while fast.next != slow:
            fast = fast.next
        fast.next = None
        return
    while slow.next != fast.next:
        slow = slow.next; fast = fast.next
    fast.next = None

if __name__ == "__main__":
    a = Node(1); b = Node(2); c = Node(3)
    a.next = b; b.next = c; c.next = b
    print("Before:", removeLoop is not None)  # just placeholder
    removeLoop(a)
    # verify by trying to traverse (will stop because loop removed)
    t = a
    cnt = 0
    while t and cnt < 10:
        print(t.data, end=" ")
        t = t.next; cnt += 1
    print()
