#include "problem_10_05_sparseSearch.h"

namespace chapter_10 {
    int sparseSearchHelper(const std::vector<std::string>& array, const std::string& query, int start, int end) {
        // check terminating conditions
        if (start > end) {
            return -1;
        }
        int midpoint = (end - start) / 2 + start;

        // handle comparison against empty string
        std::string comparisonValue = array[midpoint];
        int leftPotentialMidpoint = midpoint;
        int rightPotentialMidpoint = midpoint;
        if (comparisonValue == "") {
            std::string leftPotentialComparisonValue = comparisonValue;
            std::string rightPotentialComparisonValue = comparisonValue;
            while ((leftPotentialMidpoint > start || rightPotentialMidpoint < end) && leftPotentialComparisonValue == "" && rightPotentialComparisonValue == "") {
                // search left
                if (leftPotentialMidpoint > start) {
                    leftPotentialMidpoint --;
                    leftPotentialComparisonValue = array[leftPotentialMidpoint];
                }
                // search right
                if (rightPotentialMidpoint < end) {
                    rightPotentialMidpoint ++;
                    rightPotentialComparisonValue = array[rightPotentialMidpoint];
                }

                // check if left midpoint is non-empty
                if (leftPotentialComparisonValue != "") {
                    comparisonValue = leftPotentialComparisonValue;
                    midpoint = leftPotentialMidpoint;
                    break;
                }
                // check if right midpoint is non-empty
                if (rightPotentialComparisonValue != "") {
                    comparisonValue = rightPotentialComparisonValue;
                    midpoint = rightPotentialMidpoint;
                    break;
                }
            }
            if (leftPotentialComparisonValue == "" && rightPotentialComparisonValue == "") {
                return -1;  // the array contains only ""; there no possibility of a match
            }
        }

        // check terminating conditions after midpoint adjustment
        if (array[midpoint] == query) {
            return midpoint;
        }
        else if (start == end) {
            return -1;
        }

        // recurse left - do not include array elements that are known to be empty
        if (query >= array[start] && query <= array[midpoint]) {
            int newLocation = (leftPotentialMidpoint < (midpoint - 1) ? leftPotentialMidpoint : (midpoint - 1));
            return sparseSearchHelper(array, query, start, newLocation);
        }
        else {  // recurse right - do not include array elements that are known to be empty
            int newLocation = (rightPotentialMidpoint > (midpoint + 1) ? rightPotentialMidpoint : (midpoint + 1));
            return sparseSearchHelper(array, query, newLocation, end);
        }
    }

    int sparseSearch(const std::vector<std::string>& array, const std::string& query) {
        return sparseSearchHelper(array, query, 0, array.size() - 1);
    }
}
