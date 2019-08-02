#include "problem_16_03_intersection.h"

namespace chapter_16 {
    Point2* intersection(const LineSegment2& s1,
                         const LineSegment2& s2){
        // follow book implementation: ignore vertical slopes, ignore colinear overlap
        // check slope equality
        // if slopes are not equal, assume lines are infinite and compute their intersection
        // then determine if this intersection is within the bounds of the segments
        if (!approxEqual(s1._m, s2._m)) {
            /*
             * y = m1x + b1
             * y = m2x + b2
             * m1x + b1 = m2x + b2
             * (m1 - m2)x = b2 - b1
             * x = (b2 - b1) / (m1 - m2)
             * y = m1x + b
             */
            float xIntersection = (s2._b - s1._b) / (s1._m - s2._m);
            auto intersection = new Point2(xIntersection, s1._m * xIntersection + s1._b);
            if (s1.inBounds(*intersection) && s2.inBounds(*intersection)) {
                return intersection;
            }
            else {
                delete intersection;
                return nullptr;
            }
        }
        else {  // if slope equal, only endpoint equality indicates intersection
            if (s1._p1 == s2._p1 || s1._p1 == s2._p2) {
                auto intersection = new Point2(s1._p1);
                return intersection;
            }
            if (s1._p2 == s2._p1 || s1._p2 == s2._p2) {
                auto intersection = new Point2(s1._p2);
                return intersection;
            }
            return nullptr;
        }
    }
}