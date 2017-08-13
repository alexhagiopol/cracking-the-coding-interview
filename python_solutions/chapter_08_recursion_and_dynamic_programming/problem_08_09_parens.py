def parens(n):
    if n <= 0:
        return ['']
    else:
        combinations = []
        helper('', n, n, combinations)
        return combinations


def helper(string, left, right, combinations):
    if left <= 0 and right <= 0:
        combinations.append(string)
    else:
        if left > 0:
            helper(string + '(', left - 1, right, combinations)
        if right > left and right > 0:
            helper(string + ')', left, right - 1, combinations)
