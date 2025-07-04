"""
Метод ветвей и границ
Оптимизация: если длинна маршрута при заходе в определенный город больше текущего минимума (answer) рекурсивный вызов для этого города не выполняется
Также если длинна пути на 1 меньше количества городов, то рекурсивный вызов тоже не выполняется - минимум обновляется сразу
(так как мы знаем следующий город (а соответственно и расстояние до него от текущего) до следующего рекурсивного вызова)

Тесты:
4
0 20 42 35
20 0 30 34
42 30 0 12
35 34 12 0
Ответ - 97

5
0 100 162 162 100
100 0 100 162 162
162 100 0 100 162
162 162 100 0 100
100 162 162 100 0
Ответ - 500

5
0 20 18 12 8
5 0 14 7 11
12 18 0 6 11
11 17 11 0 12
5 5 5 5 0
Ответ - 41

5
0 90 80 40 100
60 0 40 50 70
50 30 0 60 20
10 70 20 0 50
20 40 50 20 0
Ответ - 180
"""

answer = 10000000000
result_way = []


def commivoyager(now: int, cities: list[list[int]], length: int, used: list[bool], n: int, way: list[int]) -> None:
    global answer, result_way
    is_entry = False
    is_entry: bool
    if len(way) == n - 1:
        is_entry = True

    for i in range(n):
        path = cities[now][i]
        path: int
        if path + length < answer and not is_entry and not used[i]:
            new_used = [True if used[j] else False for j in range(n)]
            new_used[i] = True
            commivoyager(i, cities, length + path, new_used, n, way + [i])
        elif not used[i] and is_entry and cities[i][0] + path + length < answer:
            answer = length + path + cities[i][0]
            result_way = way + [i] + [0]


length_ = int (input())
cities_ = [list(map(int, input().split())) for _ in range(length_)]
used_ = [False] * length_
commivoyager(0, cities_, 0, used_, length_, [])
print(answer)
print(*result_way)
