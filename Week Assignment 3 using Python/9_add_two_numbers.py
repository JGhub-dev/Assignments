# 9. Add two numbers represented by linked lists (digits reversed)
class Node:
    def __init__(self,data):
        self.data=data; self.next=None

def addTwoLists(l1, l2):
    dummy = Node(0); tail = dummy; carry = 0
    while l1 or l2 or carry:
        s = carry + (l1.data if l1 else 0) + (l2.data if l2 else 0)
        carry = s // 10
        tail.next = Node(s % 10)
        tail = tail.next
        if l1: l1 = l1.next
        if l2: l2 = l2.next
    return dummy.next

if __name__ == "__main__":
    a = Node(3); a.next = Node(4); a.next.next = Node(2)  # 243
    b = Node(4); b.next = Node(6); b.next.next = Node(5)  # 564
    res = addTwoLists(a,b)
    t = res
    while t:
        print(t.data, end=" ")
        t = t.next
    print()
