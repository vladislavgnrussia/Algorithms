def merge(v1: list[int], v2: list[int]) -> list[int]:
    result = [0] * (len(v1) + len(v2))
    p1 = 0
    p2 = 0
    for i in range(len(v1) + len(v2)):
        if p1 == len(v1) or p2 < len(v2) and v1[p1] > v2[p2]:
            result[i] = v2[p2]
            p2 += 1
        else:
            result[i] = v1[p1]
            p1 += 1
    return result


def merge_sort(v: list[int]) -> list[int]:
    if len(v) == 1:
        return v
    v1 = v[:len(v) // 2]
    v2 = v[len(v) // 2:]
    return merge(merge_sort(v1), merge_sort(v2))


print(*merge_sort(list(map(int, input().split()))))
