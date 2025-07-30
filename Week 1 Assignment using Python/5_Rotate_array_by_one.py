
def rotate_by_one(arr):
    return [arr[-1]] + arr[:-1]

arr = [1, 2, 3, 4, 5]
print(rotate_by_one(arr))
