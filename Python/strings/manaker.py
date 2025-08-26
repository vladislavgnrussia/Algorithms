def manaker(string: str) -> list[int]:
    sz = len(string)
    result = [0] * sz
    center = 0
    radius = 0
    for index in range(1, sz):
        if index <= center + radius:
            result[index] = min(result[2 * center - index], center + radius - index)

        left = index - result[index] - 1
        right = index + result[index] + 1

        while left > -1 and right < sz and string[left] == string[right]:
            left -= 1
            right += 1
            result[index] += 1

        if right > center + radius:
            center = index
            radius = result[index]

    return result

print(*manaker(input()))

