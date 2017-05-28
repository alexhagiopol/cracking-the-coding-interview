def compute_compressed_length(string):
    if string is None:
        return 0
    if len(string) == 1:
        return 2
    compressed_length = 2
    for i in range(1, len(string)):
        if string[i] == string[i - 1]:
            compressed_length += 0
        else:
            compressed_length += 2
    return compressed_length


def string_compression(string):
    if string is None:
        return None
    if len(string) <= compute_compressed_length(string):
        return string
    compressed = string[0]
    num_dupes = 1
    for i in range(1, len(string)):
        if string[i] == string[i-1]:
            num_dupes += 1
        else:
            compressed += str(num_dupes) + string[i]
            num_dupes = 1
    compressed += str(num_dupes)
    return compressed


