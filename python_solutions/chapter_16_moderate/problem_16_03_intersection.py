class Point2:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y


class LineSegment:
    def __init__(self, start, end):
        self.start = start
        self.end = end
        if self.start.x > self.end.x:  # reorder points in X order
            temp = self.start
            self.start = self.end
            self.end = temp
        self.M = (self.end.y - self.start.y) / (self.end.x - self.start.x)  # slope of segment
        self.B = self.start.y - self.M * self.start.x  # y intercept of infinite line


def intersection(segment1, segment2):
    # follow book implementation: ignore vertical slopes, ignore colinear overlap
    if segment1.M != segment2.M:  # slopes not equal: intersection happens if infinite line intersection point is within range of both segments
        x_intersection = (segment2.B - segment1.B) / (segment1.M - segment2.M)
        y_intersection_1 = segment1.M * x_intersection + segment1.B
        y_intersection_2 = segment2.M * x_intersection + segment2.B
        assert(y_intersection_1 == y_intersection_2)
        if segment1.start.x <= x_intersection <= segment1.end.x and segment2.start.x <= x_intersection <= segment2.end.x:
            intersection_point = Point2(x_intersection, y_intersection_1)
            return intersection_point
    else:  # slopes equal: intersection happens only if endpoints are identical
        if segment1.start == segment2.start or segment1.start == segment2.end:
            return segment1.start
        if segment1.end == segment2.start or segment1.end == segment2.end:
            return segment1.end
    return None
