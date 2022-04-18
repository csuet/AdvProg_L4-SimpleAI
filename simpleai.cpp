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
    //Write your code here
    for (auto x:vocabulary){
        if (x.size()==wordLen)
        answer.push_back(x);
    }
    return answer;
}

@@ -41,7 +44,12 @@ vector<string> filterWordsByLen(int wordLen, const vector<string>& vocabulary)
char nextCharWhenWordIsNotInDictionary(const set<char>& selectedChars)
{
    char answer;
    //Write your code here
    for (char i='a'; i<='z'; i++){
        if (selectedChars.find(i)==selectedChars.end()){
            answer=i;
            break;
        }
    }
    return answer;
}

@@ -55,7 +63,11 @@ char nextCharWhenWordIsNotInDictionary(const set<char>& selectedChars)
map<char, int> countOccurrences(const vector<string>& candidateWords)
{
    map<char, int> answer;
    //Write your code here
    for (auto x:candidateWords){
        for (auto ch:x){
            ++answer[ch];
        }
    }
    return answer;
}

@@ -70,7 +82,16 @@ map<char, int> countOccurrences(const vector<string>& candidateWords)
char findMostFrequentChar(const map<char, int>& occurrences, const set<char>& selectedChars)
{
    char answer;
    //Write your code here
    int max=0;
    for (auto x: selectedChars){
        for (auto y:occurrences){
            if (y.second>max&&selectedChars.count(y.first)==0){
                max=y.first;
                answer=y.second;
            }
        }
    }

    return answer;
}

@@ -86,6 +107,8 @@ char findBestChar(const vector<string>& candidateWords, const set<char>& selecte
{
    char answer;
    //Write your code here
    map<char, int> frequent = countOccurrences(candidateWords);
    answer = findMostFrequentChar(frequent, selectedChars);
    return answer;
}

@@ -108,8 +131,11 @@ string getWordMask(char nextChar)

bool isCorrectChar(char ch, const string& mask)
{
    bool answer;
    bool answer = false;
    //Write your code here
    for(auto x:mask){
        if(x == ch) answer = true;
    }
    return answer;
}

@@ -123,8 +149,11 @@ bool isCorrectChar(char ch, const string& mask)
***/
bool isWholeWord(const string& mask)
{
     bool answer;
     bool answer = true;
    //Write your code here
    for(auto ch:mask){
        if(ch == MASK_CHAR) answer = false;
    }
    return answer;
}

@@ -142,8 +171,13 @@ bool isWholeWord(const string& mask)
***/
bool wordConformToMask(const string& word, const string& mask, char ch) 
{
    bool answer;
    bool answer = true;
    //Write your code here
    for(int i = 0; i < word.size(); i++){
        if(mask[i] != MASK_CHAR){
            if(mask[i] != word[i]) answer = false;
        }
    }
    return answer;
}

@@ -163,5 +197,8 @@ vector<string> filterWordsByMask(const vector<string>& words, const string& mask
{
    vector<string> answer;
    //Write your code here
    for(auto x:words){
        if(wordConformToMask(x, mask, ch)) answer.push_back(x);
    }
    return answer;
} 
}
