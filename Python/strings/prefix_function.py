def prefix(string):

    sz = len(string)
    result = [0]
    llp = 0
    ok = False

    for index in range(1, sz):

        if string[llp] == string[index]:
            result += [llp + 1]
            llp += 1
            continue

        while llp != 0:
            llp = result[llp - 1]
            if string[llp] == string[index]:
                result += [llp + 1]
                llp += 1
                ok = True
                break

        if not ok:
            result += [0]
        ok = False

    return result


str = input()
print(*prefix(str))
