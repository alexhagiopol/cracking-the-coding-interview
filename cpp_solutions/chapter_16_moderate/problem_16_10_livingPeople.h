/*
 * PROBLEM: Given a list of people with their birth and death years, implement a method to compute the year
 * with the most number of people alive. You may assume that all people were born between 1900 and 2000 (inclusive).
 * If a person was alive during any portion of that year, they should be included in that year's count. For example,
 * Person (birth = 1908, death = 1909) is included in the counts for both 1908 and 1909.
 *
 * TEST CASES: see tests.cpp
 *
 * ALGORITHM:
 * 0. Create an array of ints with a number of elements equal to the number of years range.
 * 1. Iterate over all people. For each person, increment the array element corresponding to
 * the person's birth. Decrement the array element corresponding to the year *after* the
 * person's death.
 * 2. Iterate over the array of years keeping a sum of all the elements seen so far, a "maxSum"
 * with the highest value sum ever seen, and the year that the maxSum was recorded.
 * 3. Return the year of the maxSum.
 *
 * TIME COMPLEXITY: O(N)
 * SPACE COMPLEXITY: O(1)
 */

#pragma once

namespace chapter_16 {
    struct Person {
        int birth;
        int death;
        Person(int _birth, int _death) : birth(_birth), death(_death) {};
    };

    int livingPeople(const std::vector<Person>& people, int startYear, int endYear) {
        assert(startYear < endYear);
        const int numYears = endYear - startYear + 1;  // 101 years from 1900 to 2000
        std::vector<int> years(numYears, 0);
        for (const Person& p : people) {
            if (p.birth >= startYear && p.birth <= endYear) {
                years[p.birth - startYear]++;
            }
            if (p.death >= startYear && p.death < endYear) { // strict less than to conform to rule (see below)
                years[p.death + 1 - startYear] --;  // rule in problem statement: if someone was alive for any part of a year
                                                    // they are considered to have been alive the whole year
            }
        }
        int bestYear = startYear;
        int mostPeople = 0;
        int currentPeople = 0;
        for (int i = 0; i < numYears; i++) {
            currentPeople += years[i];
            if (currentPeople > mostPeople) {
                mostPeople = currentPeople;
                bestYear = i + startYear;
            }
        }
        return bestYear;
    }
}
