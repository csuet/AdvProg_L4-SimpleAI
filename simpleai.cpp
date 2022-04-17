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

/***
    Args:
        wordLen (int): The desired length of input word
        vocabulary (vector<string>): The vocabulary
    Returns:
        answer (vector<string>) : A set or word from the vocabulary where the number of character is equal to wordLen
***/
vector<string> filterWordsByLen(int wordLen, const vector<string>& vocabulary)
{
    vector<string> answer;
    for (int i = 0; i < vocabulary.size(); ++ i) {
        if (vocabulary[i].size() == wordLen) {
            answer.push_back(vocabulary[i]);
        }
    }
    return answer;
}
vector<string> filterWordsByLen(int wordLen, const vector<string>& vocabulary)
char nextCharWhenWordIsNotInDictionary(const set<char>& selectedChars)
{
    char answer;
    for (char c = 'a'; c <= 'z'; ++ c) {
        if (selectedChars.find(c) == selectedChars.end()) {
            answer = c;
            break;
        }
    }
    //Write your code here
    return answer;
}
char nextCharWhenWordIsNotInDictionary(const set<char>& selectedChars)
map<char, int> countOccurrences(const vector<string>& candidateWords)
{
    map<char, int> answer;

    for (int i = 0; i < candidateWords.size(); ++ i) {
        string word = candidateWords[i];

        for (char c: word) {
            answer[c] ++;
        }
    }
    //Write your code here
    return answer;
}
map<char, int> countOccurrences(const vector<string>& candidateWords)
char findMostFrequentChar(const map<char, int>& occurrences, const set<char>& selectedChars)
{
    char answer;
    int max = 0;

    for (auto p : occurrences) {
        if (selectedChars.find(p.first) == selectedChars.end()) {
            if (p.second > max) {
                max = p.second;
                answer = p.first;
            }
        }
    }
    //Write your code here
    return answer;
}
char findMostFrequentChar(const map<char, int>& occurrences, const set<char>& se
char findBestChar(const vector<string>& candidateWords, const set<char>& selectedChars)
{
    char answer;
    map <char, int> occurrences = countOccurrences(candidateWords);
    answer = findMostFrequentChar(occurrences, selectedChars);
    return answer;
}
string getWordMask(char nextChar)

bool isCorrectChar(char ch, const string& mask)
{
    bool answer = false;
    for (int i = 0; i < mask.size(); ++ i) {
        if (mask[i] != '-') {
            answer = true;
            break;
        }
    }
    return answer;
}
bool isCorrectChar(char ch, const string& mask)
***/
bool isWholeWord(const string& mask)
{
    bool answer = true;
    for (int i = 0; i < mask.size(); ++ i) {
        if (mask[i] == '_') {
            answer = false;
            break;
        }
    }
    return answer;
}
bool isWholeWord(const string& mask)
***/
bool wordConformToMask(const string& word, const string& mask, char ch) 
{
    bool answer = true;
    for (int i = 0; i < mask.size(); ++ i) {
        if (mask[i] != '-') {
            if (mask[i] != word[i]) {
                answer = false;
                break;
            }
        }
    }
    return answer;
}

bool wordConformToMask(const string& word, const string& mask, char ch)
vector<string> filterWordsByMask(const vector<string>& words, const string& mask, char ch)
{
    vector<string> answer;
    for (int i = 0; i < words.size(); ++ i) {
        if (wordConformToMask(words[i], mask, ch)) {
            answer.push_back(words[i]);
        }
    }
    return answer;
}
