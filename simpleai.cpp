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
    for ( int i=0; i < vocabulary.length(); i++)  {
        if ( wordLen == vocabulary[i].length() ) answer.push_back(vocabulary[i]);
    }
    return answer;
}

char nextCharWhenWordIsNotInDictionary(const set<char>& selectedChars)
{
    char answer;
    for ( char ch = 'a', ch <= 'z', ch++ ) {
        if ( selectedChars.count(ch) == 0 ) answer = ch;
    }
    return answer;
}


map<char, int> countOccurrences(const vector<string>& candidateWords)
{
    map <char, int> answer;
    for( int i=0; i<candidateWords.length(); i++ ) {
        for( int j=0; j<candidateWords[i].length(); j++)  {
            answer[candidateWords[i][j]]++;
        }
    }
    return answer;
}


char findMostFrequentChar(const map<char, int>& occurrences, const set<char>& selectedChars)
{
    char answer;
    int max = 0;
    for( auto i:count ) {
        if( i.second() > most ) {
            answer = i.first;
            max = i.second;
        }
    }
    return answer;
}


char findBestChar(const vector<string>& candidateWords, const set<char>& selectedChars)
{
    char answer;
    map<char, int> frequent = countOccurrences(candidateWords);
    answer = findMostFrequentChar(frequent, selectedChars);
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
    for (int i = 0; i < mask.length(); i++) {
        if ( ch == mask[i] ) return true;
    }
    return answer;
}


bool isWholeWord(const string& mask)
{
     bool answer;
    answer = true;
    for (int i = 0; i < mask.length(); i++) {
        if (mask[i] == MASK_CHAR) answer = false;
    return answer;
}


bool wordConformToMask(const string& word, const string& mask, char ch) 
{
    bool answer;
    answer = true;
    if (!isCorrectChar(ch, mask)) return false;
    for ( int i = 0; i < word.length(); i++ ) {
        if (mask[i] != '_' && mask[i] != word[i])  return false;
    }
    return answer;
}


vector<string> filterWordsByMask(const vector<string>& words, const string& mask, char ch)
{
    vector<string> answer;
    for( int i=0; i<word.length(); i++ ) {
        if(wordConformToMask(word[i], mask, ch)) answer.push_back(word[i]);
    }
    return answer;
}