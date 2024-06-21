#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to preprocess the bad character heuristic
void preprocessBadCharacter(const string& pattern, vector<int>& badChar) {
    int m = pattern.size();
    badChar.assign(256, -1);
    for (int i = 0; i < m; ++i) {
        badChar[tolower(pattern[i])] = i;
    }
}

// Function to perform string matching using Boyer-Moore algorithm with case insensitivity
void boyerMooreCaseInsensitive(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    
    // Preprocess bad character heuristic
    vector<int> badChar(256, -1);
    preprocessBadCharacter(pattern, badChar);
    
    int s = 0; // Shift of the pattern with respect to text
    while (s <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && tolower(pattern[j]) == tolower(text[s + j])) {
            j--;
        }
        if (j < 0) {
            cout << "Pattern found at index " << s << endl;
            s += (s + m < n) ? m - badChar[tolower(text[s + m])] : 1;
        } else {
            s += max(1, j - badChar[tolower(text[s + j])]);
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

    boyerMooreCaseInsensitive(text, pattern);

    return 0;
}

