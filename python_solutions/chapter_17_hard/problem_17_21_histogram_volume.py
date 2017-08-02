def histogram_volume(histogram_array):
    left_max_array = len(histogram_array) * [0]
    right_max_array = len(histogram_array) * [0]
    # traverse left to right to get max from left
    left_max_height = 0
    for index in range(0, len(histogram_array)):
        height = histogram_array[index]
        if height > left_max_height:
            left_max_height = height
        left_max_array[index] = left_max_height
    # traverse from right to left to get max from right
    right_max_height = 0
    for index in range(len(histogram_array) - 1, -1, -1):
        height = histogram_array[index]
        if height > right_max_height:
            right_max_height = height
        right_max_array[index] = right_max_height
    # final traversal:
    water_volume = 0
    for index in range(0, len(histogram_array)):
        water_volume += min(left_max_array[index], right_max_array[index]) - histogram_array[index]
    return water_volume
