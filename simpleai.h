#ifndef SIMPLEAI_H
#define SIMPLEAI_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
 
#include "util.h"

using namespace std;

int readMaxGuess();
int readWordLen();
vector<string> filterWordsByLen(int wordLen, const vector<string>& vocabulary);
map<char, int> countOccurrences(const vector<string>& candidateWords);
char findMostFrequentChar(const map<char, int>& occurrences, const set<char>& selectedChars);
char findBestChar(const vector<string>& candidateWords, const set<char>& selectedChars);
string getWordMask(char nextChar);
bool isCorrectChar(char ch, const string& mask);
bool isWholeWord(const string& mask);
char nextCharWhenWordIsNotInDictionary(const set<char>& selectedChars);
vector<string> filterWordsByMask(const vector<string>& words, const string& mask, char ch);
bool wordConformToMask(const string& word, const string& mask, char ch);

const char MASK_CHAR = '-';
#endif