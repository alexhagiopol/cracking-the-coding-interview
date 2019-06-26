def partition(array, start, end):
    partition_index = start
    partition_value = array[end]
    # perform parition operation:
    # swap element to lowest index with unknown partition assignment
    for i in range(start, end + 1):
        if array[i] <= partition_value:
            array[i], array[partition_index] = array[partition_index], array[i]
            partition_index += 1
    return partition_index - 1  # - 1 to undo the increment operation after the final swap of the partitionValue


def quick_sort_helper(array, start, end):
    if start < end:
        partition_index = partition(array, start, end)
        quick_sort_helper(array, start, partition_index - 1)
        quick_sort_helper(array, partition_index + 1, end)


def quick_sort(array):
    quick_sort_helper(array, 0, len(array) - 1)
