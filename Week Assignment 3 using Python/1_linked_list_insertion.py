# 1. Linked list insertion - insert at end
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def insertAtEnd(head, data):
    newNode = Node(data)
    if not head:
        return newNode
    t = head
    while t.next:
        t = t.next
    t.next = newNode
    return head

if __name__ == "__main__":
    head = None
    head = insertAtEnd(head, 10)
    head = insertAtEnd(head, 20)
    head = insertAtEnd(head, 30)
    t = head
    while t:
        print(t.data, end=" ")
        t = t.next
    print()
