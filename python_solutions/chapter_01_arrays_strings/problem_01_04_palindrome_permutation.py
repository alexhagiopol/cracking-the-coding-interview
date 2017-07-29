def palindrome_permuation(string):
    if string is None:
        return True
    dict = {}
    num_valid_chars = 0
    for char in string:
        if char != ' ':
            num_valid_chars += 1
            if dict.get(char, None) is not None:
                dict[char] = not dict[char]  # flip bit
            else:
                dict[char] = True  # initialize with odd number
    if num_valid_chars % 2 == 0:  # even length. expect all chars to have even value i.e. False
        return sum(1 for x in dict.values() if x is True) == 0
    return sum(1 for x in dict.values() if x is True) == 1  # odd length. expect all chars except 1 to have even value i.e. False

