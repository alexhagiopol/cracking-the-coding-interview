# no memoization
def is_combination(string, dict):
    for i in range(1, len(string)):
        s1 = string[0:i]
        s2 = string[i:]
        if s1 in dict:
            if s2 in dict:
                return True
            return is_combination(s2, dict)
    return False


def find_longest_combination(list):
    dict = {}
    for string in list:
        dict[string] = True
    sorted_list = list
    sorted_list.sort(key=len)  # built in sort from shortest to longest
    for string in sorted_list[::-1]:  # we want to traverse in order from longest to shortest
        if is_combination(string, dict):
            return string
    return None
