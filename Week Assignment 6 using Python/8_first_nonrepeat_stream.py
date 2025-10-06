from collections import deque

def FirstNonRepeating(stream):
    q = deque()
    freq = [0]*26
    res = ''
    for ch in stream:
        idx = ord(ch)-97
        freq[idx]+=1
        q.append(ch)
        while q and freq[ord(q[0])-97]>1:
            q.popleft()
        res += q[0] if q else '#'
    return res
