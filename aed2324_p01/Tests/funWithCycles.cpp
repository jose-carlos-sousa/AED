#include "funWithCycles.h"

//=============================================================================
// Exercise 1: Palindromes
//=============================================================================
// TODO
// The right side of the string is equal to the inverse of the left side s[::i]= s[i::]
//no incio da it i sabemos que os i-1 char são iguais aos len-i+1...
// length/2-i+1 at most i ise length and the the loop var is 1 and it decreases while i increases
bool FunWithCycles::palindrome(const std::string & s) {
                    unsigned length = s.size();
                for (unsigned i = 0; i < length/2; i++)
                 if (s[i] != s[length-i-1])
                 return false;
                return true;
    return false;
}


//=============================================================================
// Exercise 2: Palindrome Sentences
//=============================================================================
// TODO
bool FunWithCycles::palindromeSentence(const std::string & s) {
    std::string newString="";
    for(int i=0; i<s.size();i++){
        if(std::isalpha(s[i])){
            newString+=tolower(s[i]);
        }
    }
    return palindrome(newString) ;
}


//=============================================================================
// Exercise 3: Interesting Numbers
//=============================================================================
// TODO
int FunWithCycles::nextInterestingNumber(int n, int sum) {

    bool answerFound=false;
    int number=n+1;
    while(!answerFound){




        if (digitSum(number)==sum){

            return number;
            answerFound=true;
        }else{
            number+=1;
        }

    }
    return 0;
}
// This auxiliary function should return the sum of the digits of n
// TODO
int FunWithCycles::digitSum(int n) {
    int numberHelp=n;
    int sum=0;
    while(numberHelp!=0){
        sum+= numberHelp%10;
        numberHelp=numberHelp/10;

    }
    return sum;
}


//=============================================================================
// Exercise 4: Winter is coming
//=============================================================================
// TODO
int FunWithCycles::winter(const vector<int> & v) {
    if(v.size()==1 or v.size()==0){return 0;}
    bool loading=false;
    int max=0;
    int curSize=0;
    for( int i=1; i< v.size();i++){
        std::cout<<curSize<<endl;
        if(loading==false and  v[i]< v[i-1]){
            loading=true;
            curSize=1;

        }else if( loading==true and v[i]< v[i-1]){
            curSize+=1;



        }else{
            loading=false;
        }
        if(v[i]< v[i-1]){
            if(curSize> max){max=curSize;}
        }

    }
    return max;
}


//=============================================================================
// Exercise 5: Playing with vectors
//=============================================================================

// a) count
// TODO
int FunWithCycles::count(const vector<int> & v, int n) {
    int count=0;
    for(int i=0;i< v.size(); i++){
        if(v[i]==n){count++;}
    }
    return count;
}

// b) hasDuplicates
// TODO
bool FunWithCycles::hasDuplicates(const vector<int> & v) {
    std::map<int,int> myMap;
    for(int i=0;i<v.size(); i++){
        if(myMap.find(v[i])!= myMap.end()){return true;}
        else{myMap[v[i]]=1;}
    }

    return false;
}

// c) removeDuplicates
// TODO
void FunWithCycles::removeDuplicates(vector<int> & v) {
    std::vector<int> myArr;
    std::map<int,int> myMap;
    for(int i=0;i<v.size(); i++){
        if(myMap.find(v[i])!= myMap.end()){}
        else{myMap[v[i]]=1;
        myArr.push_back(v[i]);}
    }
    v=myArr;




}

// d) merge
// TODO
vector<int> FunWithCycles::merge(const vector<int> & v1, const vector<int> & v2) {
    int p1=0;
    int p2=0;
    vector<int> ans;
    while(p1!= v1.size() or p2 != v2.size()){
        if(p1!= v1.size() and p2 != v2.size()){
            if(v1[p1]< v2[p2]){
                ans.push_back(v1[p1]);
                p1++;
            }else{
                ans.push_back(v2[p2]);
                p2++;

            }
        }else if(p1== v1.size() and p2 != v2.size()){
            ans.push_back(v2[p2]);
            p2++;
        }else{
            ans.push_back(v1[p1]);
            p1++;

        }

    }

    return ans;
}


//=============================================================================
// Exercise 6: Playing with prime numbers
//=============================================================================

// a) isPrime
// TODO
bool FunWithCycles::isPrime(int n) {
    if(n==0 or n==1 ){return false;}
    for(int i=2; i<n;i++){
        if(n%i==0){return false;}
    }
    return true;
}

// b) factorize
// TODO
vector<int> FunWithCycles::factorize(int n) {
    std::vector<int> myVector;
    int k=2;
    while(n!=1){


            if(n%k==0){
                myVector.push_back(k);
                n=n/k;
            }else{
                k++;
            }


    }

    return myVector;
}

// c) listPrimes
// TODO
vector<int> FunWithCycles::listPrimes(int n) {

    vector<int> ans;
    for(int i=2; i<=n; i++){
        if(isPrime(i)){ans.push_back(i);}
    }
    return ans;
}
