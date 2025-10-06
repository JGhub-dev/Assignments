from queue import Queue

def modifyQueue(q, k):
    stack = []
    for _ in range(k):
        stack.append(q.get())
    while stack:
        q.put(stack.pop())
    for _ in range(q.qsize() - k):
        q.put(q.get())
    return q
