#include "simpleai.h"

int readMaxGuess()
{
    int maxGuess;
    cout << endl << "Enter the number of incorrect guesses: ";
    cin >> maxGuess;
    return maxGuess;
}

int readWordLen()
{
    int wordLen;
    cout << endl << "Enter the number characters of your secret word: ";
    cin >> wordLen;
    return wordLen;
    
}

vector<string> filterWordsByLen(int wordLen, const vector<string>& vocabulary)
{
    vector<string> answer;
    for(int i = 0; i < (int)vocabulary.size(); i++) {
        int x = vocabulary[i].size();
        if(x == wordLen) answer.push_back(vocabulary[i]);
    }
    return answer;
}

char nextCharWhenWordIsNotInDictionary(const set<char>& selectedChars)
{
    char answer;
    for(char c = 'a'; c <= 'z'; c++) {
        if(selectedChars.find(c) == selectedChars.end()) answer = c;
    }
    return answer;
}

map<char, int> countOccurrences(const vector<string>& candidateWords)
{
    map<char, int> answer;
    for(int i = 0; i < (int)candidateWords.size(); i++) {
        string s = candidateWords[i];
        for(int j = 0; j < (int)s.size(); j++) {
            answer[s[j]]++;
        }
    }
    return answer;
}

char findMostFrequentChar(const map<char, int>& occurrences, const set<char>& selectedChars)
{
    char answer;
    int cur_max = 0;
    for(char c: selectedChars) {
        int x = occurrences.find(c)->second;
        if(x > cur_max) {
            cur_max = x;
            answer = c;
        }
    }
    return answer;
}

char findBestChar(const vector<string>& candidateWords, const set<char>& selectedChars)
{
    char answer;
    map<char, int> mchar = countOccurrences(candidateWords);
    answer = findMostFrequentChar(mchar, selectedChars);
    return answer;
}

string getWordMask(char nextChar)
{
    string mask;
    cout << "The next char is: " << nextChar << endl;
    cout << "Please give me your answer: ";
    cin >> mask;
    return mask;
}

bool isCorrectChar(char ch, const string& mask)
{
    bool answer;
    answer = false;
    for(int i = 0; i < (int) mask.size(); i++){
        if(mask[i] == ch){
            answer = true;
            break;
        }
    }
    return answer;
}

bool isWholeWord(const string& mask)
{
    bool answer;
    answer = true;
    for(int i = 0; i < (int) mask.size(); i++){
        if(mask[i] == MASK_CHAR){
            answer = false;
            break;
        }
    }
    return answer;
}

bool wordConformToMask(const string& word, const string& mask, char ch) 
{
    bool answer = true;
    for(int i = 0; i < (int) word.size(); i++){
        if(!isCorrectChar(ch, mask)) {
            answer = false;
            break;
        } else if(word[i] != mask[i] and mask[i] != MASK_CHAR) {
            answer = false;
            break;
        }
    }
    return answer;
}

vector<string> filterWordsByMask(const vector<string>& words, const string& mask, char ch)
{
    vector<string> answer;
    for(int i = 0; i < (int) words.size(); i++) {
        if(wordConformToMask(words[i], mask, ch)) {
            answer.push_back(words[i]);
        }
    }
    return answer;
}