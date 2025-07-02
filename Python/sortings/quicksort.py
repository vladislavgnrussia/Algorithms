def quicksort(arr: list[int]) -> list[int]:
    if len(arr) < 2:
        return arr
    elif len(arr) == 2:
        return arr if arr[0] < arr[1] else arr[::-1]
    low = arr[0]
    high = arr[-1]
    medium = arr[len(arr) // 2]
    median = low + high + medium - min(low, high, medium) - max(low, high, medium)
    more = []
    less = []
    equals = []
    for element in arr:
        if element < median:
            less += [element]
        elif element == median:
            equals += [median]
        else:
            more += [element]
    return quicksort(less) + equals + quicksort(more)


print(*quicksort(list(map(int, input().split()))))
