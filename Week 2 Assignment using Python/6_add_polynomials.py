def addPolynomial(p1, p2):
    result = []
    i = j = 0
    while i < len(p1) and j < len(p2):
        if p1[i][1] > p2[j][1]:
            result.append(p1[i])
            i += 1
        elif p1[i][1] < p2[j][1]:
            result.append(p2[j])
            j += 1
        else:
            result.append((p1[i][0] + p2[j][0], p1[i][1]))
            i += 1
            j += 1
    result.extend(p1[i:])
    result.extend(p2[j:])
    return result
