def permutations_with_dups(string):
    hash_table = {}
    permutations = []
    for character in string:
        if character in hash_table:
            hash_table[character] += 1
        else:
            hash_table[character] = 1
    helper('', hash_table, permutations)
    return permutations


def helper(string, hash_table, permutations):
    if sum(hash_table.values()) <= 0:
        permutations.append(string)
    else:
        for character in hash_table:
            local_hash_table = hash_table.copy()
            if local_hash_table[character] <= 1:
                local_hash_table.pop(character, None)
            else:
                local_hash_table[character] -= 1
            helper(string + character, local_hash_table, permutations)
