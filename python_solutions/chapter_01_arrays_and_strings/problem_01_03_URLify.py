# in Python, strings are immutable, thus we are forced to implement with lists of single strings
def URLify(string):
    # compute length of new string
    new_len = 0
    i1 = len(string) - 1  # index at end of string
    for char in string:
        if char == ' ':
            new_len += 3
        else:
            new_len += 1
    # extend length of string to fit URL
    string += [' '] * (new_len - len(string))
    i2 = len(string) - 1  # index at end of string
    # traverse using double index technique to do this "in place"
    while i1 >= 0 and i2 >= 0:
        if string[i1] == ' ':
            string[i2] = '0'
            string[i2 - 1] = '2'
            string[i2 - 2] = '%'
            i1 -= 1
            i2 -= 3
        else:
            string[i2] = string[i1]
            i1 -= 1
            i2 -= 1
    return string
