# 2. Delete node in doubly linked list
class Node:
    def __init__(self,data):
        self.data=data; self.next=None; self.prev=None

def push(head, data):
    n = Node(data); n.next = head
    if head: head.prev = n
    return n

def delete_node(head, key):
    cur = head
    while cur and cur.data != key: cur = cur.next
    if not cur: return head
    if cur.prev: cur.prev.next = cur.next
    else: head = cur.next
    if cur.next: cur.next.prev = cur.prev
    return head

def to_list(head):
    res=[]; cur=head
    while cur: res.append(cur.data); cur=cur.next
    return res

if __name__ == "__main__":
    head = None
    for i in range(5,0,-1): head = push(head,i) # 1..5
    print(to_list(head))
    head = delete_node(head, 3); print(to_list(head))
    head = delete_node(head, 1); print(to_list(head))
    head = delete_node(head, 10); print(to_list(head))
