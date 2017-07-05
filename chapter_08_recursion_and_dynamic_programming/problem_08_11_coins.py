# unoptimized and no memoization
def coin_representations(n, denominations=(1, 5, 10, 25)):
    if n == 0:
        return 1
    if len(denominations) <= 0:  # check for case where we don't ever pick any coins
        return 0
    coin = denominations[-1]
    branches = n // coin
    representations = 0
    while branches >= 0:
        representations += coin_representations(n - branches*coin, denominations[0:-1])
        branches -= 1
    return representations
