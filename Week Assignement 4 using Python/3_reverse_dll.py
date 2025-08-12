# 3. Reverse a doubly linked list
class Node:
    def __init__(self,data):
        self.data=data; self.next=None; self.prev=None

def push(head,data):
    n=Node(data); n.next=head
    if head: head.prev = n
    return n

def reverse_dll(head):
    cur = head; temp = None; new_head = head
    while cur:
        temp = cur.prev
        cur.prev = cur.next
        cur.next = temp
        new_head = cur
        cur = cur.prev
    return new_head

def to_list(head):
    res=[]; cur=head
    while cur: res.append(cur.data); cur=cur.next
    return res

if __name__ == "__main__":
    head=None
    head = push(head,3); head=push(head,2); head=push(head,1) # 1,2,3
    print(to_list(head))
    head = reverse_dll(head)
    print(to_list(head))
