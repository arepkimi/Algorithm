#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to preprocess the bad character heuristic
void preprocessBadCharacter(const string& pattern, vector<int>& badChar) {
    int m = pattern.size();
    badChar.assign(256, m); // Initialize all characters with a jump of pattern size
    for (int i = 0; i < m - 1; ++i) {
        badChar[pattern[i]] = m - 1 - i; // Last occurrence distance of character from the end of pattern
    }
}

// Function to perform string matching using Boyer-Moore-Horspool algorithm with case sensitivity
void boyerMooreHorspoolCaseSensitive(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    
    // Preprocess bad character heuristic
    vector<int> badChar;
    preprocessBadCharacter(pattern, badChar);
    
    int s = 0; // Shift of the pattern with respect to text
    while (s <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }
        if (j < 0) {
            cout << "Pattern found at index " << s << endl;
            s += badChar[text[s + m]]; // Jump according to bad character heuristic
        } else {
            s += badChar[text[s + m - 1]]; // Jump according to bad character heuristic
        }
    }
}

int main() {
    string text, pattern;

    // Asking user for text and pattern
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);

    boyerMooreHorspoolCaseSensitive(text, pattern);

    return 0;
}

