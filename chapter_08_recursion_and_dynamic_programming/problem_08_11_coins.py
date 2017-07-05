# unoptimized and no memoization
def coin_representations(n, denom_index=0, denoms=(1, 5, 10, 25)):
    if n == 0:  # base case: we've found a combination of coins that divides evenly into amount of change
        return 1
    if denom_index >= len(denoms):  # check for case where we don't ever pick any coins
        return 0
    coin = denoms[denom_index]  # current coin we pick. we only pick one type of coin at each recursion level
    branches = n // coin  # max number of times we can pick this coin.
    representations = 0
    while branches >= 0:  # subtract coin value from n for each recursive call. there is one case where we pick 0 coins!
        representations += coin_representations(n - branches*coin, denom_index + 1, denoms)
        branches -= 1
    return representations
