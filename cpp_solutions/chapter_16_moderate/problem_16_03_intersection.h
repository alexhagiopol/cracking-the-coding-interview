#pragma once

namespace chapter_16 {
    struct Point2 {
        float _x;
        float _y;
        Point2(float x, float y) : _x(x), _y(y) {};
        Point2(const Point2& other) : _x(other._x), _y(other._y) {};
        bool operator==(const Point2& other) {
            return other._x == _x && other._y == _y;
        }
    };

    struct Line2 {
        float _m;
        float _b;
        Line2(float m, float b) : _m(m), _b(b){};
    };

    struct LineSegment2 {
        Point2 _p1;
        Point2 _p2;
        LineSegment2(const Point2& p1, const Point2& p2) : _p1(p1), _p2(p2) {};
    };

    Point2* intersection(const LineSegment2& s1,
                         const LineSegment2& s2);
};