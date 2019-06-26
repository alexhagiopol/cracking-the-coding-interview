import copy


def merge_helper(array, helper_array, start, middle, end):
    assert(len(array) == len(helper_array))
    left_idx = start
    right_idx = middle + 1
    helper_idx = start
    # perform merge operation from left and right halves of input array into helper array
    # this operation stops when either the left or right subarray is depleted
    while left_idx <= middle and right_idx <= end:
        if array[left_idx] <= array[right_idx]:
            helper_array[helper_idx] = array[left_idx]
            left_idx += 1
        else:
            helper_array[helper_idx] = array[right_idx]
            right_idx += 1
        helper_idx += 1
    # account for case where one array segment (left or right) is smaller
    # only one of these while blocks will be executed because only one side may be smaller
    while left_idx <= middle:
        helper_array[helper_idx] = array[left_idx]
        left_idx += 1
        helper_idx += 1
    while right_idx <= middle:
        helper_array[helper_idx] = array[right_idx]
        right_idx += 1
        helper_idx += 1
    # copy content of helper array into input array at the appropriate indices
    for i in range(0, len(array)):
        array[i] = helper_array[i]  # cannot use array = helper_array due to Python mutability rules


def sort_helper(array, helper_array, start, end):
    assert(len(array) == len(helper_array))
    if start < end:
        middle = (end - start) // 2 + start
        if start < middle:
            sort_helper(array, helper_array, start, middle)
        if (middle + 1) < end:
            sort_helper(array, helper_array, middle + 1, end)
        merge_helper(array, helper_array, start, middle, end)


def merge_sort(array):
    helper_array = copy.deepcopy(array)
    start = 0
    end = len(array) - 1
    sort_helper(array, helper_array, start, end)
