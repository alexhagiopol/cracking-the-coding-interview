def is_unique(input):
    dict = [False]*128
    for letter in input:
        index = ord(letter)
        if dict[index] == True:
            return False
        dict[index] = True
    return True
