#include "problem_16_10_livingPeople.h"

namespace chapter_16 {
    int livingPeople(const std::vector<Person>& people, int startYear, int endYear) {
        if (startYear >= endYear) return startYear;
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

