def magic_index(A, start=None, end=None):
    if start is None:
        start = 0
    if end is None:
        end = len(A) - 1
    if len(A) < 1 or end - start < 0:
        return None
    i = (end + start) // 2
    if i == A[i]:
        return i
    if i < A[i]:
        return magic_index(A, 0, i)
    return magic_index(A, i+1, end)
