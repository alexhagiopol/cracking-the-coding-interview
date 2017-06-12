def convert_to_base2(num):
    # little endian
    bin = ''
    while num:
        num, mod = divmod(num, 2)
        bin += str(mod)
    return bin[::-1]


def int_to_char(mod):
    if mod < 10:
        return str(mod)
    return chr(ord('a') + mod - 10)


def convert_to_base(num, old, new):
    # little endian
    num_ten = int(str(num), old)
    new_num = ''
    while num_ten:
        num_ten, mod = divmod(num_ten, new)
        new_num += int_to_char(mod)
    return new_num[::-1]


