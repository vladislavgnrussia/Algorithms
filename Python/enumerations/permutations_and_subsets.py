def gen_all_permutations(arr: list[...], v: list[int], n: int) -> None:
    if len(v) == n:
        print(*v, sep='')
    else:
        for i in range(len(arr)):
            if arr[i] is not None:
                new_arr = arr.copy()
                new_arr[i] = None
                gen_all_permutations(new_arr, v + [arr[i]], n)

def gen_all_subsets(narr: list[...], v: list[int], n: int) -> None:
    arr = narr.copy()
    if len(v) == n:
        print(*v, sep='')
    else:
        for i in range(len(arr)):
            if arr[i] is not None:
                el = arr[i]
                arr[i] = None
                gen_all_subsets(arr, v + [el], n)

array = list(map(int, input().split()))
for length in range(1, len(array) + 1):
    gen_all_subsets(array, [], length)