# 5. Josephus problem (recursive)
def josephus(n,k):
    if n==1: return 1
    return (josephus(n-1,k)+k-1) % n + 1

if __name__ == "__main__":
    print(josephus(7,3))
    print(josephus(5,2))
