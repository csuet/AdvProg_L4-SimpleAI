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
//Hàm trả về tập các từ có độ dài là wordLen
}

char nextCharWhenWordIsNotInDictionary(const set<char>& selectedChars)
{
//Hàm trả về kí tự khi từ đoán không có trong từ điển
   return 0;
}

map<char, int> countOccurrences(const vector<string>& candidateWords)
{
// Hàm đếm số lần xuất hiện của các từ
}

char findMostFrequentChar(const map<char, int>& occurrences, const set<char>& selectedChars)
{
// hàm tìm kí tự hay xuất hiện nhất
}

/***
Tìm kí tự xuất hiện nhiều nhất
- Cài đặt cách 1: nếu xuất hiện nhiều lần trong 1 word thì cũng đếm nhiều lần
- Cách 2 (ko cài ở đây): nếu xuất hiện nhiền lần trong 1 word thì chỉ đểm một lần
***/
char findBestChar(const vector<string>& candidateWords, const set<char>& selectedChars)
{

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
// Hàm kiểm tra kí tự đã đoán có đúng hay không
}

bool isWholeWord(const string& mask)
{
// hàm kiểm tra xem đầu vào có phải là cả từ hay không
}

bool wordConformToMask(const string& word, const string& mask, char ch)
{
//Hàm kiếm tra xem từ và mask có cùng dạng hay không
}

vector<string> filterWordsByMask(const vector<string>& words, const string& mask, char ch)
{
//Hàm lọc các từ dựa vào tập từ đầu vào, mask của nguời dùng và kí tự đang chọn
}
