
def second_largest(arr):
    first = second = -1
    for num in arr:
        if num > first:
            second = first
            first = num
        elif num > second and num != first:
            second = num
    return second

arr = [10, 20, 4, 45, 99]
print(second_largest(arr))
