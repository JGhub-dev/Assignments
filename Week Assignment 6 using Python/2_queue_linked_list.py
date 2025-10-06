class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Queue:
    def __init__(self):
        self.front = self.rear = None

    def enqueue(self, x):
        temp = Node(x)
        if not self.rear:
            self.front = self.rear = temp
            return
        self.rear.next = temp
        self.rear = temp

    def dequeue(self):
        if not self.front:
            return -1
        temp = self.front
        self.front = self.front.next
        if not self.front:
            self.rear = None
        return temp.data
