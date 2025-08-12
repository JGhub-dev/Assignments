# 4. Insert in Circular Linked List
class Node:
    def __init__(self,data):
        self.data=data; self.next=None

def insert_after(head, after_val, data):
    if not head:
        n = Node(data); n.next = n; return n
    cur = head
    while True:
        if cur.data == after_val: break
        cur = cur.next
        if cur == head: break
    n = Node(data); n.next = cur.next; cur.next = n
    return head

def to_list(head):
    if not head: return []
    res = []
    cur = head
    while True:
        res.append(cur.data)
        cur = cur.next
        if cur == head: break
    return res

if __name__ == "__main__":
    head = None
    head = insert_after(head, 0, 10)
    head = insert_after(head, 10, 20)
    head = insert_after(head, 20, 30)
    print(to_list(head))
    head = insert_after(head, 20, 25)
    print(to_list(head))
