#include "problem_08_04_powerSet.h"

namespace chapter_08{
    void createPowerSet(std::vector<int> set, std::vector<std::vector<int>>& powerSet){
        if(set.size() == 0){
            std::vector<int> emptySet = {};
            powerSet.push_back(emptySet);
            return;
        }
        int lastElement = set.back();
        set.pop_back();
        std::vector<std::vector<int>> newSets = {};
        createPowerSet(set, powerSet);
        for(auto subproblemSet : powerSet){
            subproblemSet.push_back(lastElement);
            newSets.push_back(subproblemSet);
        }
        powerSet.insert( powerSet.end(), newSets.begin(), newSets.end() );
    };
}

