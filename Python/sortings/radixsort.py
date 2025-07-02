MAX_CATEGORY = 9  # константа, означающая максимальный разряд в числах, встречающихся во входных данных
# например, если в условии сказано, что в массиве входных данных числа по модулю не превосходят 10^9, то эта константа равна 9
# сложность ~ O(MAX_CATEGORY * N) - при определенных входных данных работает быстрее NlogN - сортировок
# categoty - разряд


def radixsort(v: list[int], current_category: int) -> list[int]:
    if len(v) == 1 or current_category == -1:
        return v
    rad = pow(10, current_category)
    radix = []
    for i in range(19):
        radix.append([].copy())
    result = []
    for el in v:
        radix[(el // rad) % 10 + 9].append(el)
    for element in radix:
        a = 1
        if len(element) != 0:
            a += 1
            element = radixsort(element, current_category - 1)
            result += element
    return result


print(*radixsort(list(map(int, input().split())), MAX_CATEGORY))
