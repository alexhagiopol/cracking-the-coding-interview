def permutations_no_dups(string):
    if len(string) <= 0:
        return None
    if len(string) == 1:
        return [string[0]]
    subproblem_permutations = permutations_no_dups(string[1:])
    new_permutations = []
    for subproblem_permutation in subproblem_permutations:
        new_permutations.extend(create_permutations(subproblem_permutation, string[0]))
    return new_permutations


def create_permutations(string, inserted_character):
    permutations = []
    for index in range(0, len(string)):
        permutations.append(string[0:index] + inserted_character + string[index:])
    permutations.append(string + inserted_character)
    return permutations
