def count_at_most_k(s, k):
    freq = {}
    left = 0
    res = 0
    for right in range(len(s)):
        freq[s[right]] = freq.get(s[right], 0) + 1
        while len(freq) > k:
            freq[s[left]] -= 1
            if freq[s[left]] == 0:
                del freq[s[left]]
            left += 1
        res += right - left + 1
    return res

def count_exactly_k(s, k):
    return count_at_most_k(s, k) - count_at_most_k(s, k - 1)

s = input().strip()
k = int(input())
print(count_exactly_k(s, k))