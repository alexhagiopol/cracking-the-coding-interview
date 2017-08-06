def flip_bit_to_win(number):
    binary_representation = bin(number)[2:]
    if len(binary_representation) <= 1:
        return 1
    tally = 0  # tally started before we've seen a zero "first sequence lengh"
    new_tally = 0  # tally started after first zero "second sequence length"
    max_length = 0  # largest sum of first and second sequences we've seen so far
    zero_already_seen = False  # is the current index before or after a zero in the current considered sequence?

    for index, bit in enumerate(list(binary_representation)):
        if bit == '1':
            tally += 1
            if zero_already_seen:  # if this 1 is after a zero, increment new_tally since these ones may contribute to a new sequence later
                new_tally += 1
        if bit == '0':
            if zero_already_seen:  # start a new sequence
                zero_already_seen = False
                if tally > max_length:  # check if last sequence was the longest so far
                    max_length = tally
                    tally = new_tally + 1  # new sequence starts. we add all the post-zero ones we've seen *and* we +1 for the bit flip
                new_tally = 0  # reset new tally until we see the "first" zero of this new sequence
            else:
                zero_already_seen = True
                tally += 1  # we add 1 to tally even though this is a zero to account for possible flip
    if tally > max_length:
        max_length = tally
    return max_length
