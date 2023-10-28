#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"

using namespace std;

WordMean::WordMean(string w, string m): word(w), meaning(m) {}

string WordMean::getWord() const {
    return word;
}

string WordMean::getMeaning() const {
    return meaning;
}

void WordMean::setMeaning(string m) {
    meaning = m;
}

void WordMean::setWord(string w) {
    word = w;
}

set<WordMean> Dictionary::getWords() const {
	return words;
}

void Dictionary::addWord(WordMean wm)  {
    words.insert(wm);
}


//=============================================================================
// Exercise 1: Dictionary
//=============================================================================
//TODO
bool WordMean::operator< (const WordMean& wm2) const {
     return word<wm2.word;
}

//=============================================================================
// Subexercise 1.1: Create Dictionary
//=============================================================================
//TODO
void Dictionary::readFile(ifstream &f) {


    string line;
    string line1="";
    string line2="";
    int i=0;
    while(getline(f,line)){
        if(i==0){
            line1=line;
            i++;
        }else{
            line2=line;
            i--;
            addWord(WordMean(line1,line2));

        }

    }

}

//=============================================================================
// Subexercise 1.2: Print Dictionary
//=============================================================================
//TODO
bool Dictionary::update(string w1, string m1) {

    set<WordMean>::iterator it=words.begin();
    while(it!=words.end()){
        if(it->getWord()==w1){
            words.erase(it);
            this->addWord(WordMean(w1,m1));

            return true;
        }

        it++;
    }
    this->addWord(WordMean(w1,m1));
    return false;
}

//=============================================================================
// Subexercise 1.3: Consult Dictionary
//=============================================================================
//TODO
string Dictionary::consult(string w1, WordMean& previous, WordMean& next) const {
    /*set<WordMean> words=getWords();
    std::set<WordMean>::iterator it;
    for( it=words.begin();it!=words.end();){
        if(it->getWord()==w1){
            return it->getMeaning();
        }
        if(it->getWord()> w1){
            next=*it;
            --it;
            previous=*it;
            it++;
            return "word not found";
        }
        it++;*/
    std::set<WordMean>::iterator value = std::lower_bound(words.begin(), words.end(), WordMean(w1,""));
    if(value!=words.end() && value->getWord()==w1){
        return value->getMeaning();}
    std::set<WordMean>::iterator r=value;
    std::set<WordMean>::iterator l=--value;
    if(r!=words.end() and l!=words.end()){
        next=*r;
        previous=*l;
        return "word not found";
    }
    else if(r!=words.end() ){
        next=*r;
        previous=WordMean("","");
        return "word not found";
    }else if(l!=words.end()){
        previous=*l;
        next=WordMean("","");
        return "word not found";
    }






    }





//=============================================================================
// Subexercise 1.4: Update Dictionary
//=============================================================================
//TODO
void Dictionary::print() const {
    for(auto element : words){
        std::cout<<element.getWord()<<endl;
        std::cout<<element.getMeaning()<<endl;

    }
}
