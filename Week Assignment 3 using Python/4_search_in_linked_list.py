# 4. Search in linked list
class Node:
    def __init__(self,data):
        self.data=data; self.next=None

def searchList(head, key):
    t = head
    while t:
        if t.data == key: return True
        t = t.next
    return False

if __name__ == "__main__":
    head = Node(5); head.next = Node(10)
    print(searchList(head, 10))
    print(searchList(head, 7))
