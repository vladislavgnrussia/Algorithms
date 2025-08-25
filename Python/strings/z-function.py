def z_function(string: str) -> list[int]:
    sz = len(string)
    zblock = [0, 0]
    result = [0] * sz
    for index in range(1, sz):
        if index <= zblock[1]:
            result[index] = min(result[index - zblock[0]], zblock[1] - index + 1)

        left = result[index]
        while index +  left < sz and string[left] == string[left + index]:
            left += 1

        if left > zblock[1]:
            zblock[1] = left - 1 + index
            zblock[0] = index

        result[index] = left

    return result

s = input()
print(*z_function(s))

