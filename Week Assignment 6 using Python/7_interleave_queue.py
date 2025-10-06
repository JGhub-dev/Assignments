from queue import Queue

def interLeaveQueue(q):
    n = q.qsize()
    half = n // 2
    stack = []
    for _ in range(half):
        stack.append(q.get())
    while stack:
        q.put(stack.pop())
    for _ in range(half):
        q.put(q.get())
    for _ in range(half):
        stack.append(q.get())
    while stack:
        q.put(stack.pop())
        q.put(q.get())
    return q
