class Queue:
    def __init__(self):
        self.q = []

    def enqueue(self, x):
        self.q.append(x)

    def dequeue(self):
        if not self.q:
            return -1
        return self.q.pop(0)

    def front(self):
        return self.q[0] if self.q else -1
