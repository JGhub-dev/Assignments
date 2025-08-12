# 10. Hackerrank: Print elements of linked list
class Node:
    def __init__(self,data):
        self.data=data; self.next=None

def display(head):
    t = head
    while t:
        print(t.data)
        t = t.next

if __name__ == "__main__":
    head = Node(1); head.next = Node(2); head.next.next = Node(3)
    display(head)
