#include "problem_05_06_conversion.h"

namespace chapter_05{
    int conversion(int A, int B){
        int count = 0;
        while(A > 0 || B > 0){
            if(A & 1){
                if (!(B & 1)){
                    count ++;
                }
            } else {
                if (B & 1){
                    count ++;
                }
            }
            A >>= 1;
            B >>= 1;
        }
        return count;
    }
}
