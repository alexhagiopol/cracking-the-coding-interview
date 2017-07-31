def is_substring(s1, s2):
    return s1 in s2


def string_rotation(s1, s2):
    return is_substring(s2, s1 + s1)
