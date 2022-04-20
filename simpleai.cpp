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
    for(auto i : vocabulary) {
        if(i.size() == wordLen) answer.push_back(i);
    }
    return answer;
}

char nextCharWhenWordIsNotInDictionary(const set<char>& selectedChars)
{
    char answer;
    for(int i = 'a'; i <= 'z'; i++){
        if(selectedChars.count(i) == 0){
            answer = i;
            break;
        }
    }
    return answer;
}

map<char, int> countOccurrences(const vector<string>& candidateWords)
{
    map<char, int> answer;
    for(auto i : candidateWords){
        for(auto j : i){
            answer[j]++;
        }
    }

    return answer;
}

char findMostFrequentChar(const map<char, int>& occurrences, const set<char>& selectedChars)
{
    char answer;
    int max = 0;
    for(auto i : occurrences){
        if(selectedChars.count(i.first) == 0 && i.second > max) {
            answer = i.first;
            max = i.second;
        }
    }
    return answer;
}

char findBestChar(const vector<string>& candidateWords, const set<char>& selectedChars)
{
    char answer;
    map <char, int> occurrences = countOccurrences(candidateWords);
    answer = findMostFrequentChar(occurrences, selectedChars);
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
    bool answer = false;
    for(auto i : mask){
        if(i == ch){
            answer = true;
            break;
        }
    }
    return answer;
}

bool isWholeWord(const string& mask)
{
    bool answer = true;
    for(auto i : mask){
        if(i == '-'){
            answer = false;
            break;
        }
    }
    return answer;
}

bool wordConformToMask(const string& word, const string& mask, char ch) 
{
    bool answer = true;
    for(int i = 0; i < mask.size(); i++) {
        if(mask[i] != '-' && mask[i] != word[i]) {
            answer = false;
            break;
        }
    }
    return answer;
}

vector<string> filterWordsByMask(const vector<string>& words, const string& mask, char ch)
{
    vector<string> answer;
    for(auto i : words) {
        if(wordConformToMask(i, mask, ch)){
            answer.push_back(i);
        }
    }

    return answer;
}