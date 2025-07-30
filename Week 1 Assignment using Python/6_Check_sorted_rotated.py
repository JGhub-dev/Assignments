
def is_sorted_and_rotated(arr):
    count = 0
    for i in range(len(arr)):
        if arr[i] > arr[(i + 1) % len(arr)]:
            count += 1
    return count <= 1

arr = [3, 4, 5, 1, 2]
print("Yes" if is_sorted_and_rotated(arr) else "No")
