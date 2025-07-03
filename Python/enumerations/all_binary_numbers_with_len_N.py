def gen(v: list[int], n: int) -> None:
    if len(v) == n:
        print(*v, sep='')
    else:
        gen(v + [0], n)
        gen(v + [1], n)

n = int(input())
gen([], n)
