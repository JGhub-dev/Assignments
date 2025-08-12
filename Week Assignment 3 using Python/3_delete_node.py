# 3. Delete a node (first occurrence)
class Node:
    def __init__(self,data):
        self.data=data; self.next=None

def deleteNode(head, key):
    if not head: return None
    if head.data == key:
        return head.next
    prev = head
    cur = head.next
    while cur and cur.data != key:
        prev = cur; cur = cur.next
    if cur:
        prev.next = cur.next
    return head

if __name__ == "__main__":
    head = Node(1); head.next = Node(2); head.next.next = Node(3)
    head = deleteNode(head, 2)
    t = head
    while t:
        print(t.data, end=" ")
        t = t.next
    print()
