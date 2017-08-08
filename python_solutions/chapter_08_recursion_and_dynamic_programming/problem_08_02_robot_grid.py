def robot_grid(maze, start, end):
    path = []
    visited_points = {}
    if get_path(maze, start, end, path, visited_points):
        return path
    return None


def get_path(maze, start, end, path, visited_points):
    # check if we're done
    if end == start:
        path.append(end)
        return True
    # check visited             check valid grid cell
    if end in visited_points or not maze[end[0]][end[1]]:
        return False
    # check out of bounds
    if not 0 <= end[0] <= len(maze) or not 0 <= end[1] <= len(maze[0]):
        return False
    # DFS-like strategy
    if get_path(maze, start, (end[0] - 1, end[1]), path, visited_points) or get_path(maze, start, (end[0], end[1] - 1), path, visited_points):
        path.append(end)
        return True
    visited_points[end] = True
    return False
