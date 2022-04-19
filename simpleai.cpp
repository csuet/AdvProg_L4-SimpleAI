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
    int i = 0;
    while (i < vocabulary.size()) {
        if(vocabulary[i].length() == wordLen) answer.push_back(vocabulary[i]);
        i++;
    }
    //Write your code here
    return answer;
}
@@ -42,6 +47,12 @@ char nextCharWhenWordIsNotInDictionary(const set<char>& selectedChars)
{
    char answer;
    //Write your code here
    for (char c = 'a'; c <= 'z'; c++) {
        if (selectedChars.find(c) == selectedChars.end()) {
            answer = c;
            break;
        }
    }
    return answer;
}

@@ -56,6 +67,11 @@ map<char, int> countOccurrences(const vector<string>& candidateWords)
{
    map<char, int> answer;
    //Write your code here
    for (int i = 0; i < candidateWords.size(); i++) {
        for (int j = 0; j < candidateWords[i].length();j++) {
            answer[candidateWords[i][j]] += 1;
        }
    }
    return answer;
}

@@ -71,6 +87,14 @@ char findMostFrequentChar(const map<char, int>& occurrences, const set<char>& se
{
    char answer;
    //Write your code here
    int ans = 0;
    for(char c : selectedChars) {
        int x = occurrences.find(c) -> second;
        if(x > ans) {
            ans = x;
            answer = c;
        }
    }
    return answer;
}

@@ -86,6 +110,8 @@ char findBestChar(const vector<string>& candidateWords, const set<char>& selecte
{
    char answer;
    //Write your code here
    map<char,int> occurrences = countOccurrences(candidateWords);
    answer = findMostFrequentChar(occurrences, selectedChars);
    return answer;
}

@@ -111,6 +137,11 @@ bool isCorrectChar(char ch, const string& mask)
    bool answer;
    //Write your code here
    return answer;
    answer = false;
    for (int i = 0; i < mask.length(); i++) {
        if (ch == mask[i]) return true;
    }
    return false;
}

/***
@@ -123,9 +154,13 @@ bool isCorrectChar(char ch, const string& mask)
***/
bool isWholeWord(const string& mask)
{
     bool answer;
    bool answer;
    //Write your code here
    return answer;
    for (int i = 0; i < mask.length(); i++) {
        if (mask[i] == '-') return false;
    }
    return true;
}

/***
@@ -142,8 +177,16 @@ bool isWholeWord(const string& mask)
***/
bool wordConformToMask(const string& word, const string& mask, char ch) 
{
    bool answer;
    //Write your code here
    bool answer = false;
    for (int i = 0; i < word.length(); i++) {
        if (mask[i] != '-' && word[i] != mask[i]) {
            return answer;
        }
    }
    if (isCorrectChar(ch, mask)) {
        answer = true;
    }
    return answer;
}

@@ -163,5 +206,10 @@ vector<string> filterWordsByMask(const vector<string>& words, const string& mask
{
    vector<string> answer;
    //Write your code here
    for(int i = 0; i<words.size(); i++) {
        if (wordConformToMask(words[i], mask, ch)) {
            answer.push_back(words[i]);
        }
    }
    return answer;
} 
