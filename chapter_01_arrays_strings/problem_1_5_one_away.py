def one_away(s1, s2):
    if abs(len(s1) - len(s2)) > 1:
        return False  # different by more than 1 edit
    i1 = i2 = 0
    differenceFound = False
    while i1 < len(s1) and i2 < len(s2):
        if s1[i1] == s2[i2]:
            i1 += 1
            i2 += 1
        else:
            if differenceFound is True:  # there has already been one edit found. different by more than 1 edit
                return False
            else:
                differenceFound = True
                if len(s1) > len(s2):  # potential insertion
                    i1 += 1
                elif len(s1) < len(s2): # potential insertion
                    i2 += 1
                else: # potential replacement
                    i1 += 1
                    i2 += 1
    return True  # if we haven't returned by now, the strings are 1 or 0 edits different