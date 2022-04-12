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
    for(int i = 0 ; i < vocabulary.size(); i++){
        if(vocabulary[i].size() == wordLen) answer.push_back(vocabulary[i]);
    }
    return answer;
}

@@ -42,6 +45,11 @@ char nextCharWhenWordIsNotInDictionary(const set<char>& selectedChars)
{
    char answer;
    //Write your code here
    for (char i = 'a'; i < 'z'; i++)
    {
        if(selectedChars.find(i) == selectedChars.end()) answer = i;
    }

    return answer;
}

@@ -56,6 +64,11 @@ map<char, int> countOccurrences(const vector<string>& candidateWords)
{
    map<char, int> answer;
    //Write your code here
    for (string word : candidateWords)
    {
        for(char i : word) answer[i] ++;
    }

    return answer;
}

@@ -71,6 +84,13 @@ char findMostFrequentChar(const map<char, int>& occurrences, const set<char>& se
{
    char answer;
    //Write your code here
    int bestCount = 0;
    for(auto i : occurrences){
        if(i.second > bestCount && selectedChars.count(i.first) == 0){
            answer = i.first;
            bestCount = i.second;
        }
    }
    return answer;
}

@@ -86,6 +106,8 @@ char findBestChar(const vector<string>& candidateWords, const set<char>& selecte
{
    char answer;
    //Write your code here
    map<char, int> freq = countOccurrences(candidateWords);
    answer = findMostFrequentChar(freq, selectedChars);
    return answer;
}

@@ -110,6 +132,13 @@ bool isCorrectChar(char ch, const string& mask)
{
    bool answer;
    //Write your code here
    answer = false;
    for(int i = 0; i < mask.size(); i++){
        if(mask[i] == ch){
            answer = true;
            break;
        }
    }
    return answer;
}

@@ -123,8 +152,15 @@ bool isCorrectChar(char ch, const string& mask)
***/
bool isWholeWord(const string& mask)
{
     bool answer;
    bool answer;
    //Write your code here
    answer = true;
    for(int i = 0; i < mask.size(); i++){
        if(mask[i] == MASK_CHAR){
            answer = false;
            break;
        }
    }
    return answer;
}

@@ -144,6 +180,16 @@ bool wordConformToMask(const string& word, const string& mask, char ch)
{
    bool answer;
    //Write your code here
    answer = true;
    for(int i = 0; i < word.size(); i++){
        if(!isCorrectChar(ch, mask)){
            answer = false;
            break;
        }else if(word[i] != mask[i] && mask[i] != MASK_CHAR){
            answer = false;
            break;
        }
    }
    return answer;
}

@@ -163,5 +209,8 @@ vector<string> filterWordsByMask(const vector<string>& words, const string& mask
{
    vector<string> answer;
    //Write your code here
    for(int i = 0; i < words.size(); i++){
        if(wordConformToMask(words[i], mask, ch)) answer.push_back(words[i]);
    }
    return answer;
}
