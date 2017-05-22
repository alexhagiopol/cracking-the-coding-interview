def convert_to_base2(num):
    # little endian
    bin = ''
    while num:
        num, mod = divmod(num, 2)
        bin += str(mod)
    return bin[::-1]
