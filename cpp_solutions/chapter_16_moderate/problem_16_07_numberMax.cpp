#include "problem_16_07_numberMax.h"

namespace chapter_16 {
    uint16_t numberMax(uint16_t A, uint16_t B) {
        uint32_t tempA = static_cast<uint32_t>(A) + 1;  // ensure we do not divide by zero in quotient computation. ensure that we do not overflow.
        uint32_t tempB = static_cast<uint32_t>(B) + 1;  // ensure we do not divide by zero in quotient computation. ensure that we do not overflow.
        bool quotientA = static_cast<bool>(tempA / tempB);  // may have value of 0 or 1
        bool quotientB = static_cast<bool>(tempB / tempA);  // may have value of 0 or 1
        // if qA and qB are both 0, then the numbers are both 0. in that case we want to divide by 1
        // if qA = 0 and qB = 1, then we want to divide by 1
        // if qA = 1 and qB = 1, then the numbers are the same and we want to divide by 2
        return (quotientA * A + quotientB * B) / ((quotientA && quotientB) + 1);
    }
}
