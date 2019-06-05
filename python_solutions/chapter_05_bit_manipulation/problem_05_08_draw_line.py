"""
PROBLEM:
A monochrome screen is stored as a single array of bytes, allowing eight consecutive pixels to be stored in one byte.
The screen has width W which is a multiple of 8. So, a screen with dimensions 2x16 will require 2x2 8-bit
integers to represent it. The goal is to write a program to draw a horizontal line given coordinates (x1, y) and (x2, y).

TEST CASES:
x1 = 1
x2 = 14
y = 1

00000000 00000000 00000000 00000000             00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000    -->      01111111 11111111 11111111 11111110
00000000 00000000 00000000 00000000             00000000 00000000 00000000 00000000

x1 = 1
x2 = 7
y = 1

00000000 00000000 00000000 00000000             00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000    -->      01111111 00000000 00000000 00000000
00000000 00000000 00000000 00000000             00000000 00000000 00000000 00000000

ALGORITHM:
Determine in which bytes x1 and x2 reside. Handle the following cases:
1. x1 < 0 || x1 > W || x2 < 0 || x2 > W || x2 > x1 || y < 0 || y > height
    Do nothing. Invalid input.
2. x1 and x2 in the same byte:
    Add (x2 - x1 + 1) 1s and left shift them by 8 - x2.
3. x1 and x2 are one whole byte apart or more
    Set all in-between bytes to 0xFF. Assign the appropriate number of 1s to the x1 and x2 bytes by left shifting a 1 and then subtracting 1.

SPACE & TIME:
Time: O(W): the number of operations required to do this procedure scale linearly with W.
Space: O(1): the amount of extra memory required to do this procedure does not scale with the input size

CODE:
"""


def stringify_screen(screen, width):
    assert (width % 8 == 0)
    string = ''
    height = len(screen) * 8 // width
    for h in range(0, height):
        for w in range(0, width // 8):
            string += format(screen[h * width // 8 + w], '#010b')[2:]
        string += '\n'
    return string


def single_byte_line(x1, x2):
    num_1s = x2 - x1 + 1
    byte = 1
    while num_1s > 1:
        byte <<= 1
        byte += 1
        num_1s -= 1
    left_shift = 8 - x2 - 1
    byte <<= left_shift
    return byte


def draw_line(screen, width, x1, x2, y):
    assert(width % 8 == 0)
    assert(0 <= x1 <= x2 <= width)
    assert(0 <= y <= len(screen) * 8 / width - 1)

    x1_byte_index = y * width // 8 + x1 // 8
    x2_byte_index = y * width // 8 + x2 // 8
    if x1_byte_index == x2_byte_index:
        screen[x1_byte_index] = single_byte_line(x1 % 8, x2 % 8)
    else:
        # draw 1s from x1 to end of its byte
        screen[x1_byte_index] = single_byte_line(x1 % 8, 7)
        # draw 1s from 0 to x2 in its byte
        screen[x2_byte_index] = single_byte_line(0, x2 % 8)
        # fill in in-between bytes with all 1s
        for index in range(x1_byte_index + 1, x2_byte_index):
            screen[index] = 255
