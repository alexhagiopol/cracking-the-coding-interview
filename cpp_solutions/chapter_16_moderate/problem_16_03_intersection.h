#pragma once
#include <algorithm>

namespace chapter_16 {
    template <typename T>
    bool approxEqual(const T& a, const T& b, float epsilon = 1e-6) {
        return (a > (b - static_cast<T>(epsilon)) && a < (b + static_cast<T>(epsilon)));
    }

    struct Point2 {
        float _x;
        float _y;
        Point2(float x, float y) : _x(x), _y(y) {};
        Point2(const Point2& other) : _x(other._x), _y(other._y) {};
        bool operator==(const Point2& other) const {
            return other._x == _x && other._y == _y;
        }
    };

    struct LineSegment2 {
        Point2 _p1;
        Point2 _p2;
        float _m;
        float _b;
        LineSegment2(const Point2& p1, const Point2& p2) : _p1(p1), _p2(p2) {
            // reorder the points in x order to make further logic easier
            if (_p1._x > _p2._x) {
                Point2 temp = _p1;
                _p1 = _p2;
                _p2 = temp;
            }
            // when constructed from two points, compute the slope and y-intercept of infinite line
            _m = (_p2._y - _p1._y) / (_p2._x - _p1._x);
            _b = _p1._y - _m * _p1._x;
        };
        bool inBounds(const Point2& p) const {
            return (p._x >= std::min(_p1._x, _p2._x) &&
                    p._x <= std::max(_p1._x, _p2._x) &&
                    p._y >= std::min(_p1._y, _p2._y) &&
                    p._y <= std::max(_p1._y, _p2._y));
        }
    };

    Point2* intersection(const LineSegment2& s1,
                         const LineSegment2& s2);
};