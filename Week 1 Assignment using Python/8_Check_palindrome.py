
def is_palindrome(s):
    return s == s[::-1]

s = "madam"
print("Yes" if is_palindrome(s) else "No")
