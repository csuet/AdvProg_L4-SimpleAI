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
    for (int i = 0 ; i < vocabulary.size(); i++)
    {
        if (vocabulary[i].size() == wordLen)
        {
            answer.push_back(vocabulary[i]);
        }
    }
    return answer;
}

char nextCharWhenWordIsNotInDictionary(const set<char>& selectedChars)
{
    char answer;
    //Write your code here
    for (char c = 'a' ; c < = 'z' ; c++)
    {
        if (selectedChars.find(c) == selectedChars.end())
        {
            answer = c;
            break;
        }
    }

    return answer;
}

map<char, int> countOccurrences(const vector<string>& candidateWords)
{
    map<char, int> res;
    for (string s : candidateWords)
    {
        for (int i = 0; i < s.size(); i++)
        {
            res[s[i]]++;
        }
    }
    return res;
}

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
    return answer;
}


char findBestChar(const vector<string>& candidateWords, const set<char>& selectedChars)
{
    char answer;
    map<char,int> occurrences = countOccurrences(candidateWords);
    answer=findMostFrequentChar(occurrences,selectedChars);
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
     if(mask.find(ch)==string::npos){
        answer = false;
    }
    return answer;
}

bool isWholeWord(const string& mask)
{
     bool answer;
    int countAlphabet = 0;
    for(int i =0 ;i<mask.length();i++){
        if(mask[i] >= 'a'&& mask[i]<= 'z'){
            countAlphabet++;
        }
    }
    if(countAlphabet != mask.length() ){
        answer = false;
    }
    return answer;
}

bool wordConformToMask(const string& word, const string& mask, char ch)
{
    bool answer;
    bool answer = true;
    if(word.find(ch)==string::npos){
        return false;
    }
    if(mask.find(ch)==string::npos){

        return false;
    }
    for(int i=0;i<mask.length();i++)
    {
        if(isalpha(mask[i])){
            mask[i]!=word[i];
            return false;
        }
    }
    return answer;
}

vector<string> filterWordsByMask(const vector<string>& words, const string& mask, char ch)
{
    vector<string> answer;
    for(int i=0;i<words.size();i++){
        if(wordConformToMask(words[i],mask,ch)){
            answer.push_back(words[i]);
        }
    }
    return answer;
}
