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
    return true;
}

//=============================================================================
// Subexercise 1.3: Consult Dictionary
//=============================================================================
//TODO
string Dictionary::consult(string w1, WordMean& previous, WordMean& next) const {
    return "";
}

//=============================================================================
// Subexercise 1.4: Update Dictionary
//=============================================================================
//TODO
void Dictionary::print() const {
}
