def power_set(set):
    if len(set) == 0:
        return [[]]
    subproblem_subsets = power_set(set[0:-1])
    new_subsets = []
    for subset in subproblem_subsets:
        new_subsets += [subset + [set[-1]]]
    return subproblem_subsets + new_subsets
