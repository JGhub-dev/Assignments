
def move_zeros(arr):
    result = [x for x in arr if x != 0]
    result.extend([0] * (len(arr) - len(result)))
    return result

arr = [0, 1, 0, 3, 12]
print(move_zeros(arr))
