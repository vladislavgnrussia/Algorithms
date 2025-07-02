# Функция основана на алгоритме быстрой сортировки
# Суть задачи следующая: необходимо определить к-ый по величине элемент массива
# Можно, например, отсортировать массив за О(NlogN) и получить к-ый элемент
# А можно за О(N) следующим образом:

def kth_largest_element(arr: list[int], k: int) -> int:
    if len(arr) < 2:
        return arr[0]
    elif len(arr) == 2:
        return arr[k] if arr[0] < arr[1] else arr[::-1][k]
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
    if k < len(less):
        return kth_largest_element(less, k)
    elif k < len(less) + len(equals):
        return equals[0]
    else:
        return kth_largest_element(more, k - len(less) - len(equals))


print(kth_largest_element(list(map(int, input().split())), int(input())))
