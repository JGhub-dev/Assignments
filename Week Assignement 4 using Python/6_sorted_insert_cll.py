# 6. Sorted insert for circular linked list
class Node:
    def __init__(self,data):
        self.data=data; self.next=None

def sorted_insert(head, data):
    n = Node(data)
    if not head:
        n.next = n; return n
    cur = head
    # find spot
    while True:
        if cur.data <= data and cur.next.data >= data:
            n.next = cur.next; cur.next = n; return head
        cur = cur.next
        if cur == head: break
    # insert at end before head
    cur = head
    # find min node
    min_node = head
    while cur.next != head:
        cur = cur.next
        if cur.data < min_node.data: min_node = cur
    # insert before min_node
    cur.next = n; n.next = min_node
    if data < head.data: return n
    return head

def to_list(head):
    if not head: return []
    res=[]; cur=head
    while True:
        res.append(cur.data); cur=cur.next
        if cur==head: break
    return res

if __name__ == "__main__":
    head=None
    head=sorted_insert(head,20)
    head=sorted_insert(head,10)
    head=sorted_insert(head,30)
    head=sorted_insert(head,25)
    print(to_list(head))
