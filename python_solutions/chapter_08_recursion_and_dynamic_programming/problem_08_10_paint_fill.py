def paint_fill(image, target_color, location, init_color=None):
    dims = image.shape
    if location[0] >= dims[0] or location[1] >= dims[1] or location[0] < 0 or location[1] < 0:
        return  # end recursion (1) if the location is invalid
    if init_color is None:
        init_color = image[location[0], location[1]]
    if image[location[0], location[1]] == target_color or image[location[0], location[1]] != init_color:
        return  # end recursion (2) if cell color is already the target color or (3) if  cell color is not initial color
    image[location[0], location[1]] = target_color
    paint_fill(image, target_color, (location[0] - 1, location[1]), init_color)
    paint_fill(image, target_color, (location[0] + 1, location[1]), init_color)
    paint_fill(image, target_color, (location[0], location[1] - 1), init_color)
    paint_fill(image, target_color, (location[0], location[1] + 1), init_color)
    return
