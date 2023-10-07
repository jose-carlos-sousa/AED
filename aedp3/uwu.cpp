#include "funListStackQueueProblem.h"
#include "cell.h"
#include <unordered_map>
FunListStackQueueProblem::FunListStackQueueProblem() {}


//=============================================================================
// Exercise 1: Remove Higher
//=============================================================================
// TODO
list<int> FunListStackQueueProblem::removeHigher(list<int> &values, int x) {
    list<int> l1;
    for(list<int>::iterator it=values.begin();it!=values.end();){
        if (*it> x){
            int val=*it;

            l1.push_back(val);
            it=values.erase(it);

        }else{
            it++;
        }
    }

    return l1;
}


//=============================================================================
// Exercise 2: Overlapping Intervals
//=============================================================================
//TODO
list<pair<int,int>> FunListStackQueueProblem::overlappingIntervals(list<pair<int,int>> values) {
    values.sort();



    for(list<pair<int,int>>::iterator it=values.begin(); it!=values.end();){
        list<pair<int,int>>::iterator firstIt=it;
        list<pair<int,int>>::iterator secondIt=++it;
        if(secondIt==values.end()){
            return values;
        }else{
            if(firstIt->second>=secondIt->first ){

                secondIt->first=min(secondIt->first,firstIt->first);
                secondIt->second=max(secondIt->second,firstIt->second);
                it= values.erase(firstIt);

            }else{
                it++;
            }
        }

    }


    return values;
}

