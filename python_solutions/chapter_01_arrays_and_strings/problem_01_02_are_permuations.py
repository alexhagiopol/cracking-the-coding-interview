def are_permuations(s1, s2):
    if len(s1) != len(s2):
        return False
    ascii_table = 128 * [0]
    for char in s1:
        index = ord(char)
        ascii_table[index] += 1
    for char in s2:
        index = ord(char)
        ascii_table[index] -= 1
    return all(cell == 0 for cell in ascii_table)


