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


def up_div_2 (number: int) -> int:
    return number // 2 + number % 2


def multiple_palindrom(palindrom: str) -> list[str]:
    result = []
    left = None
    right = None
    size = len(palindrom)
    if  size % 2 == 0:
        left = size // 2 - 1
        right = left + 1
    else:
        left = right = size // 2

    while left != -1:
        result.append(palindrom[left : right + 1])
        print(left, right)
        left -= 1
        right += 1
    print(result)
    return result


def all_palindromes(string: str) -> list[str]:
    sz = len(string)
    new_string = "`".join(list(string))
    print(new_string)
    manaker_ = manaker(new_string)
    result = []
    for index in range(sz * 2 - 1):
        palindromes = []
        if index % 2 == 0:
            palindromes = multiple_palindrom(string[index // 2 - manaker_[index] // 2 : index // 2 + manaker_[index] // 2 + 1])
        elif manaker_[index] != 0:
            palindromes = multiple_palindrom(string[index // 2 - up_div_2(manaker_[index]) + 1 : index // 2 + up_div_2(manaker_[index]) + 1])
        result.extend(palindromes)
    return result


print(all_palindromes(input()))

