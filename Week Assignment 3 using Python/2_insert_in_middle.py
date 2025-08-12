# 2. Insert in middle of linked list
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def insertInMiddle(head, data):
    newNode = Node(data)
    if not head:
        return newNode
    slow = head; fast = head
    while fast.next and fast.next.next:
        slow = slow.next; fast = fast.next.next
    newNode.next = slow.next
    slow.next = newNode
    return head

if __name__ == "__main__":
    # 1->2->4->5
    head = Node(1); head.next = Node(2); head.next.next = Node(4); head.next.next.next = Node(5)
    head = insertInMiddle(head, 3)
    t = head
    while t:
        print(t.data, end=" ")
        t = t.next
    print()
