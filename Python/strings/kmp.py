def z_function(s: str) -> list[int]:
    sz = len(s)
    zblock = [0, 0]
    result = [0] * sz
    for index in range(1, sz):
        if index <= zblock[1]:
            result[index] = min(result[index - zblock[0]],
                                zblock[1] - index + 1)
        left = result[index]

        while left + index < sz and s[index + left] == s[left]:
            left += 1
        if index + left > zblock[1]:
            zblock[0] = index
            zblock[1] = index + left - 1

        result[index] = left
    
    return result

def kmp(s: str, t: str) -> list[tuple[int, int]]:
    z = z_function(t + '~' + s)
    #you can use prefix-function instead of z-function

    sz = len(t)
    result = []
    for i in range(len(z)):
        if z[i] == sz:
            result.append((i - sz - 1, i - 2))
    if result:
        return result
    return [(-1, -1)]

print(*kmp(s := input(),t := input()), sep='\n')

