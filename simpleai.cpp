int readMaxGuess()
{
    int maxGuess;
    cout << endl << "Enter the number of incorrect guesses: ";
    cout << endl
         << "Enter the number of incorrect guesses: ";
    cin >> maxGuess;
    return maxGuess;
}

int readWordLen()
{
    int wordLen;
    cout << endl << "Enter the number characters of your secret word: ";
    cout << endl
         << "Enter the number characters of your secret word: ";
    cin >> wordLen;
    return wordLen;

}

/***
@@ -24,10 +25,17 @@ int readWordLen()
    Returns:
        answer (vector<string>) : A set or word from the vocabulary where the number of character is equal to wordLen
***/
vector<string> filterWordsByLen(int wordLen, const vector<string>& vocabulary)
vector<string> filterWordsByLen(int wordLen, const vector<string> &vocabulary)
{
    vector<string> answer;
    //Write your code here
    // Write your code here
    for (int i = 0; i < vocabulary.size(); i++)
    {
        if (vocabulary[i].size() == wordLen)
        {
            answer.push_back(vocabulary[i]);
        }
    }
    return answer;
}

@@ -38,24 +46,39 @@ vector<string> filterWordsByLen(int wordLen, const vector<string>& vocabulary)
        answer (char) : The next character given the provided word is not in the vocabulary
***/

char nextCharWhenWordIsNotInDictionary(const set<char>& selectedChars)
char nextCharWhenWordIsNotInDictionary(const set<char> &selectedChars)
{
    char answer;
    //Write your code here
    // Write your code here
    for (char c = 'a'; c <= 'z'; c++)
    {
        if (!selectedChars.count(c))
        {
            answer = c;
            break;
        }
    }
    return answer;
}

/***
    Args:
        candidateWords (vector<string>): The candidate words for the current given string 
        candidateWords (vector<string>): The candidate words for the current given string
    Returns:
        answer (map) : The map which count the occurences of character in the set of candidate words
***/

map<char, int> countOccurrences(const vector<string>& candidateWords)
map<char, int> countOccurrences(const vector<string> &candidateWords)
{
    map<char, int> answer;
    //Write your code here
    // Write your code here
    for (const string &word : candidateWords)
    {
        for (const char &ch : word)
        {
            answer[ch]++;
        }
    }
    return answer;
}

@@ -67,25 +90,35 @@ map<char, int> countOccurrences(const vector<string>& candidateWords)
        answer (char) : The most frequent character
***/

char findMostFrequentChar(const map<char, int>& occurrences, const set<char>& selectedChars)
char findMostFrequentChar(const map<char, int> &occurrences, const set<char> &selectedChars)
{
    char answer;
    //Write your code here
    // Write your code here
    int maxFreq = INT32_MIN;
    for (auto i : occurrences)
    {
        if (i.second > maxFreq && selectedChars.count(i.first) == 0)
        {
            answer = i.first;
            maxFreq = i.second;
        }
    }
    return answer;
}

/***
    Args:
        candidateWords (vector<string>): The candidate words for the current given string 
        candidateWords (vector<string>): The candidate words for the current given string
        selectedChars (set<char>): The predicted characters
    Returns:
        answer (char) : The most suitable character for prediction
***/

char findBestChar(const vector<string>& candidateWords, const set<char>& selectedChars)
char findBestChar(const vector<string> &candidateWords, const set<char> &selectedChars)
{
    char answer;
    //Write your code here
    // Write your code here
    answer = findMostFrequentChar(countOccurrences(candidateWords), selectedChars);
    return answer;
}

@@ -106,10 +139,15 @@ string getWordMask(char nextChar)
        answer (bool) : return False if the predicted character is the wrong one, True otherwise
***/

bool isCorrectChar(char ch, const string& mask)
bool isCorrectChar(char ch, const string &mask)
{
    bool answer;
    //Write your code here
    bool answer = false;
    // Write your code here
    for (int i = 0; i < mask.size(); i++)
    {
        if (ch == mask[i])
            return true;
    }
    return answer;
}

@@ -121,10 +159,18 @@ bool isCorrectChar(char ch, const string& mask)
        (Example: -False: g__d
                  -True:  good)
***/
bool isWholeWord(const string& mask)
bool isWholeWord(const string &mask)
{
     bool answer;
    //Write your code here
    bool answer = true;
    // Write your code here
    for (int i = 0; i < mask.size(); i++)
    {
        if (!(isalpha(mask[i])))
        {
            answer = false;
            break;
        }
    }
    return answer;
}

@@ -138,12 +184,25 @@ bool isWholeWord(const string& mask)
        answer (bool) : return False if the provided mask and the given word is not in the same form.
        Example: - False: mask(-ood), char 'd' vs word(boot)
                 - True: mask(-ood), char 'd'  vs word(good)
***/
bool wordConformToMask(const string& word, const string& mask, char ch) 
bool wordConformToMask(const string &word, const string &mask, char ch)
{
    bool answer;
    //Write your code here
    // Write your code here
    int ch1 = 0, ch2 = 0;
    for (int i = 0; i < word.size(); i++)
    {
        if (mask[i] == ch)
        {
            ch1++;
        }
        if (word[i] == ch)
        {
            ch2++;
        }
    }
    if (ch1 != 0 && ch2 != 0)
        answer = true;
    return answer;
}

@@ -159,9 +218,16 @@ bool wordConformToMask(const string& word, const string& mask, char ch)
                  predicted char: d
                  Return: good,hood
***/
vector<string> filterWordsByMask(const vector<string>& words, const string& mask, char ch)
vector<string> filterWordsByMask(const vector<string> &words, const string &mask, char ch)
{
    vector<string> answer;
    //Write your code here
    // Write your code here
    for (int i = 0; i < words.size(); i++)
    {
        if (wordConformToMask(words[i], mask, ch))
        {
            answer.push_back(words[i]);
        }
    }
    return answer;
} 