/* PROBLEM:
 * Given an M x N matrix in which each row and each column is sorted in ascending order,
 * write a method to find an element.
 *
 * TEST CASE:
 * matrix =
 * { 0,  1,  2,  3,  4,  5,   6,
 *   1, 11, 21, 31, 41, 51,  61,
 *   2, 22, 32, 42, 52, 62,  72,
 *   3, 33, 43, 53, 63, 73,  83,
 *   4, 44, 54, 64, 74, 84,  94,
 *   5, 55, 65, 75, 85, 95, 105; }
 *
 *   matrixSearch(matrix, 52) -> [2, 4]
 *
 * THOUGHTS:
 * 1. The brute force approach is linear search which takes O(N*M) time.
 *
 * 2. One might think to concatenate the matrix rows into a single row and apply binary search in O(M*N) time,
 * but this is not an option. Concatenating the rows into an array does not yield a sorted array and
 * likewise for the columns.
 *
 * 3. One might think to apply  binary search to the outer rows and columns in a way that narrows
 * down the possible location of the query to a rectangular area. This is close to the right idea, but unfortunately,
 * testing equality/inequality with outer rows and columns does not guarantee that the interior of the matrix will
 * conform to the inequality rules of the outer rows and columns. For example, in the bottom row, the query 52 is
 * valued between bottom row values at horizontal indices 0 and 1, but it's true horizontal index in the matrix is 4.
 *
 * 4. We can improve on the idea from #3 and apply binary search but use matrix diagonal values for equality comparison
 * with the search query. For example, when searching for 52 in the example, we can apply binary search to the matrix
 * diagonal values [0, 21, 42, 63, 84, 105] to determine that 52 is > 42 but 52 < 63. This means that 52 is *not* in
 * the rectangular area
 * 63, 73,  83,
 * 74, 84,  94,
 * 85, 95, 105;
 *
 * and also that 52 is *not* in the rectangular area
 * 0,  1,  2,  3,
 * 1, 11, 21, 31,
 * 2, 22, 32, 42,
 *
 * Thus 52 may either be in the rectangular area
 * 3, 33, 43, 53,
 * 4, 44, 54, 64,
 * 5, 55, 65, 75,
 *
 * or 52 may be in the rectangular area
 *  4,  5,   6,
 * 41, 51,  61,
 * 52, 62,  72,
 *
 * Thus to continue the search after determining that 52 is between 42 and 63, we recurse the search algorithm on
 * the two rectangular areas that may still contain 52. We continue recursing as the rectangular areas get smaller
 * and smaller until the rectangular areas become the size of a single value. At this point we hit the terminating condition,
 * check for equality against the query, and return the coordinate indices of the single value if it is equal to the query.
 * If we continue recursing in this manner, we divide the potential search space in 2 with every level of the recursion.
 * This algorithm can be performed in place on the input matrix, but there will be one stack frame for each level of the recursion.
 * Thus, the algorithm requires O(log(M*N)) time and O(log(M*N)) space.
 *
 * This procedure requires that we implement a method for determining matrix diagonal values even for non-square matrices
 * as well as check
 *
 */

#pragma once
#include <Eigen/Dense>

namespace chapter_10 {
    struct Point2 {
        int _row;
        int _col;
        Point2(int row, int col) : _row(row), _col(col) {}
        bool operator== (const Point2& other) {
            return (_row == other._row && _col == other._col);
        }
        bool operator> (const Point2& other) {
            return (_row > other._row || _col > other._col);
        }
    };

    template <typename Type, int Rows, int Cols>
    Point2 submatrixSearchHelper(const Eigen::Matrix<Type, Rows, Cols>& matrix, const Type& query, const Point2& start, const Point2& end){
        // if starting point has higher values row and col values than ending point,
        if (start > end) return Point2(-1, -1);
        // if bottom right value is less than the query, then there is no way that the query can be contained in this submatrix
        // apply binary search to diagonal values
        return Point2(0,0);
    }

    template <typename Type, int Rows, int Cols>
    Point2 matrixSearch(const Eigen::Matrix<Type, Rows, Cols>& matrix, const Type& query) {
        return submatrixSearchHelper(matrix, query, Point2(0,0), Point2(Rows - 1, Cols - 1));
    }
}

























