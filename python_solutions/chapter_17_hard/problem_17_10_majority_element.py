def majority_element(array):
    if array is None or len(array) <= 1:
        return None
    # first candidate is the first element of the array.
    candidate = array[0]
    matched = 1  # establish single element majority
    unmatched = 0
    # FIRST PASS
    for element in array[1:]:  # identify potential majority candidate
        if matched == 0:  # no majority yet. establish single element majority
            candidate = element
            matched = 1
        if element == candidate:  # if match found, majority increases
            matched += 1
        else:
            unmatched += 1  # if match not found, majority decreases
        if unmatched >= matched:  # majority lost when matched == unmatched
            matched = 0  # start new majority calculation
            unmatched = 0
    # SECOND PASS
    count = 0
    for element in array:  # check if candidate is actually majority
        if element == candidate:
            count += 1
    if count > len(array) // 2:  # majority = strictly greater than 50% appearance
        return candidate
    return None
