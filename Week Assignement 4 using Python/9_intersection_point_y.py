# 9. Intersection point in Y shaped linked list
class Node:
    def __init__(self,data):
        self.data=data; self.next=None

def get_count(head):
    c=0; cur=head
    while cur: c+=1; cur=cur.next
    return c

def get_intersection(head1, head2):
    c1 = get_count(head1); c2 = get_count(head2)
    p1=head1; p2=head2
    if c1 > c2:
        for _ in range(c1-c2): p1=p1.next
    else:
        for _ in range(c2-c1): p2=p2.next
    while p1 and p2:
        if p1 is p2: return p1.data
        p1=p1.next; p2=p2.next
    return -1

if __name__ == "__main__":
    common = Node(9)
    a = Node(3); b = Node(2); c = Node(1)
    a.next = common; b.next = a; c.next = b
    x = Node(6); x.next = Node(7); x.next.next = common
    print(get_intersection(c, x))
