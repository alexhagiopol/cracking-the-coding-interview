#include "problem_05_02_binaryToString.h"

namespace chapter_05{
    int binaryToString(double fraction, std::string& binaryString){
        if (fraction >= 1 || fraction <= 0){
            return -1;
        }
        binaryString = "0.";
        int i = 0;
        while (fraction > 0.0 && i < 32){
            if (fraction * 2.0 >= 1.0){
                binaryString.append("1");
                fraction = fraction * 2.0 - 1.0;
            } else {
                binaryString.append("0");
                fraction *= 2.0;
            }
            i ++;
        }
        return 0;
    }
}

