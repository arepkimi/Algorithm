#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to compute the prefix table for KMP algorithm
vector<int> computePrefix(const string& pattern) {
    int m = pattern.size();
    vector<int> prefix(m);
    prefix[0] = 0;
    int k = 0;
    for (int q = 1; q < m; ++q) {
        while (k > 0 && pattern[k] != pattern[q]) {
            k = prefix[k - 1];
        }
        if (pattern[k] == pattern[q]) {
            k++;
        }
        prefix[q] = k;
    }
    return prefix;
}

// Function to perform string matching using KMP algorithm
void KMP(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> prefix = computePrefix(pattern);
    int q = 0;
    for (int i = 0; i < n; ++i) {
        while (q > 0 && pattern[q] != text[i]) {
            q = prefix[q - 1];
        }
        if (pattern[q] == text[i]) {
            q++;
        }
        if (q == m) {
            cout << "Pattern found at index " << i - m + 1 << endl;
            q = prefix[q - 1];
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

    KMP(text, pattern);

    return 0;
}

