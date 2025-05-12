#include <iostream>
#include <cstring>
#include <cctype>
#include <map>
#include <sstream>

using namespace std;

void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void mostRecent(char *text, char *word) {
    map<string, int> wordCount;
    string tempWord;
    istringstream stream(text);

    while (stream >> tempWord) {

        tempWord.erase(remove_if(tempWord.begin(), tempWord.end(), ::ispunct), tempWord.end());
        transform(tempWord.begin(), tempWord.end(), tempWord.begin(), ::tolower);
        wordCount[tempWord]++;
    }

    int maxCount = 0;
    std::string mostFrequentWord;

    for (const auto &pair : wordCount) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostFrequentWord = pair.first;
        }
    }

    strcpy(word, mostFrequentWord.c_str());
    toUpperCase(word);
}

int main() {
    char text[1001];
    char word[100];

    cout << "Введите текст (до 1000 символов): ";
    cin.getline(text, 1001);

    mostRecent(text, word);
    
    cout << "Самое часто встречающееся слово: " << word << endl;

    return 0;
}