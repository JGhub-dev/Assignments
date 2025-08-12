# 8. Pairwise swap nodes (swap data)
class Node:
    def __init__(self,data):
        self.data=data; self.next=None

def pairwise_swap(head):
    cur = head
    while cur and cur.next:
        cur.data, cur.next.data = cur.next.data, cur.data
        cur = cur.next.next
    return head

def to_list(head):
    res=[]; cur=head
    while cur: res.append(cur.data); cur=cur.next
    return res

if __name__ == "__main__":
    head = Node(1); head.next = Node(2); head.next.next = Node(3); head.next.next.next = Node(4); head.next.next.next.next = Node(5)
    print(to_list(head))
    head = pairwise_swap(head)
    print(to_list(head))
