# 1. Insert at beginning / insert in sorted DLL
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

def insert_at_beginning(head, data):
    n = Node(data)
    n.next = head
    if head: head.prev = n
    return n

def sorted_insert(head, data):
    n = Node(data)
    if not head: return n
    if data <= head.data:
        n.next = head; head.prev = n; return n
    cur = head
    while cur.next and cur.next.data < data: cur = cur.next
    n.next = cur.next
    if cur.next: cur.next.prev = n
    cur.next = n; n.prev = cur
    return head

def to_list(head):
    res = []
    cur = head
    while cur:
        res.append(cur.data); cur = cur.next
    return res

if __name__ == "__main__":
    head = None
    head = insert_at_beginning(head, 30)
    head = insert_at_beginning(head, 20)
    head = insert_at_beginning(head, 10)
    print(to_list(head))
    head = sorted_insert(head, 25); print(to_list(head))
    head = sorted_insert(head, 5); print(to_list(head))
