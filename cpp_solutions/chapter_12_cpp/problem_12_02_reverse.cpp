//
// Created by Alex Hagiopol on 9/5/17.
//

#include "problem_12_02_reverse.h"
#include <iostream>
#include <string>

namespace chapter_12{
    void reverse(char * str){  // assume str points to the first character of a null terminated string
        char * start = str;
        char * end = str;
        while(* end) end ++;  // move end pointer to the end of th string
        end --; // point to last character
        char temp;
        while (start < end){ // swap values then advance start pointer forward and end pointer backwards
            temp = * start;
            * start = * end;
            * end = temp;
            start ++;
            end --;
        }
    }
}
