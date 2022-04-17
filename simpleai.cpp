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
    for (int i = 0; i < vocabulary.size(); i++) {
        if (vocabulary[i].size() == wordLen) answer.push_back(vocabulary[i]);
    }
    return answer;
}

/***
    Args:
        selectedChars (set<char>): The predicted characters
    Returns:
        answer (char) : The next character given the provided word is not in the vocabulary
***/

char nextCharWhenWordIsNotInDictionary(const set<char>& selectedChars)
{
    char answer;
    return answer;
}

/***
    Args:
        candidateWords (vector<string>): The candidate words for the current given string 
    Returns:
        answer (map) : The map which count the occurences of character in the set of candidate words
***/

// đếm số lần xuất hiện của từng kí tự phân biệt
map<char, int> countOccurrences(const vector<string>& candidateWords)
{
    vector<char> DifferentChar;
    for (int i = 0; i < candidateWords.size(); i++) {
        for (int j = 0; j < candidateWords[i].size(); j++) {
            DifferentChar.push_back(candidateWords[i][j]);
        }
    }

    map<char, int> answer;
    for (int i = 0; i < DifferentChar.size(); i++) {
        answer[DifferentChar[i]]++;
    }
    return answer;
}

/***
    Args:
        occurrences (map<char, int>): The map which count the occurences of character in the set of candidate words
        selectedChars (set<char>): The predicted characters
    Returns:
        answer (char) : The most frequent character
***/

//tìm kí tự xuất hiện nhiều nhất và khác các kí tự đã chọn
char findMostFrequentChar(const map<char, int>& occurrences, const set<char>& selectedChars)
{
    char answer;
    int k = 0;
    for (auto x: occurrences) {
        if ((x.second > k) && (selectedChars.find(x.first) != selectedChars.end())) {
            k = x.second;
            answer = x.first;
        }
    }
    return answer;
}

/***
    Args:
        candidateWords (vector<string>): The candidate words for the current given string 
        selectedChars (set<char>): The predicted characters
    Returns:
        answer (char) : The most suitable character for prediction
***/

//chọn kí tự đó làm answer
char findBestChar(const vector<string>& candidateWords, const set<char>& selectedChars)
{
    char answer;
    answer = findMostFrequentChar(countOccurrences(candidateWords), selectedChars);
    return answer;
}

//lấy xâu mặt nạ sau lượt đoán của máy
string getWordMask(char nextChar)
{
    string mask;
    cout << "The next char is: " << nextChar << endl;
    cout << "Please give me your answer: ";
    cin >> mask;
    return mask;
}

/***
    Args:
        ch (char): The predicted character by the AI
        mask (string): The response mask by the player
    Returns:
        answer (bool) : return False if the predicted character is the wrong one, True otherwise
***/

//kiểm tra kí tự vừa đoán có nằm trong mask không
bool isCorrectChar(char ch, const string& mask)
{
    bool answer = false;
    for (int i = 0; i < mask.size(); i++) {
        if (mask[i] == ch) {
            answer = true;
            break;
        }
    }
    return answer;
}

/***
    Args:
        mask (string): The response mask by the player
    Returns:
        answer (bool) : return False if the provided mask is not a whole word, True otherwise
        (Example: -False: g__d
                  -True:  good)
***/

//kiểm tra có phải cả từ không
bool isWholeWord(const string& mask)
{
    bool answer = true;
    for (int i = 0; i < mask.size(); i++) {
        if (mask[i] == '-') {
            answer = false;
            break;
        }
    }
    return answer;
}

/***
    This function should be used to support the filterWordsByMask function below
    Args:
        mask (string): The response mask by the player
        word (string): input word
        ch (char): The predicted character by the AI
    Returns:
        answer (bool) : return False if the provided mask and the given word is not in the same form.
        Example: - False: mask(-ood), char 'd' vs word(boot)
                 - True: mask(-ood), char 'd'  vs word(good)

***/
//kiểm tra mask có cùng dạng với word ko 
bool wordConformToMask(const string& word, const string& mask, char ch) 
{
    bool answer = true;
    //Write your code here
    for (int i = 0; i < mask.size(); i++) {
        if (mask[i] != '-' && mask[i] != word[i]) {
            answer = false;
            break;
        }
    }
    return answer;
}

/***
    Args:
        mask (string): The response mask by the player
        words (vector<string>): The candidate words
        ch (char): The predicted character by the AI
    Returns:
        answer (bool) : a list of word which satisfiy the mask and the predicted character
        Examples: input words: (good,boot,hood,...)
                  input mask: -ood
                  predicted char: d
                  Return: good,hood
***/
vector<string> filterWordsByMask(const vector<string>& words, const string& mask, char ch)
{
    vector<string> answer;
    for (int i = 0; i < words.size(); i++) {
        if (wordConformToMask(words[i], mask, ch) == true) answer.push_back(words[i]);
    }
    return answer;
}