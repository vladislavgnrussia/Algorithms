# Задача о ферзях: нужно вывести все расстановки K ферзей
# на доске N*N, так чтобы они не били друг друга
# ответ выводится в форме последовательности чисел от 1 до N (длинна последовательности - N)
# i-ое число означает вертикаль ферзя, стоящего на i-ой горизонтали
# (два ферзя на одной вертикали по смыслу задачи стоять не могут)

def ttest(arr: list[int], pos: int) -> bool:
    column = len(arr)
    row1 = pos
    row2 = pos
    while column > 0:
        column -= 1
        row1 -= 1
        row2 += 1
        if arr[column] == row1 or arr[column] == row2:
            return False
    return True


def queens(arr: list[int], used: list[int], k: int, n: int) -> None:
    if len(arr) == k:
        print(*list(map(lambda x: x + 1, arr)))
    for i in range(n):
        if used[i] != 1 and ttest(arr, i):
            used[i] = 1
            queens(arr + [i], used, k, n)
            used[i] = 0


n, k = map(int, input().split())
base = [0] * n
queens([], base, k, n)
