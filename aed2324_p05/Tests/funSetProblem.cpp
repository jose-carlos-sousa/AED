#include "funSetProblem.h"
#include <map>
FunSetProblem::FunSetProblem() {}


//=============================================================================
// Exercise 2: FunSetProblem
//=============================================================================
// TODO
pair<int,int> FunSetProblem::pairSum(const vector<int> &values, int sum) {
    map<int,int> myMap;
    for(int i=0; i<values.size();i++){
        if(myMap.find(values[i])!=myMap.end()){
            return {values[i],myMap[values[i]]};

        }
        myMap[sum-values[i]]=values[i];
    }
    return make_pair(0,0);
}
