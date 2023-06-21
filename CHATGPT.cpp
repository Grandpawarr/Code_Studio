#include <iostream>
#include <string>
using namespace std;

int main() {
    int k;
    string s;
    cin >> k >> s;

    int maxLength = 0, currentLength = 0;
    char currentChar = ' ';

    for (int i = 0; i < s.length(); i++) {
        if (i == 0 || s[i] != currentChar) {
            currentLength = 1;
            currentChar = s[i];
        } else {
            currentLength++;
        }

        if (currentLength == k * 2) {
            maxLength = max(maxLength, k * 2);
        } else if (currentLength == k * 2 - 1) {
            if ((i + 1 < s.length() && s[i + 1] != currentChar) || i == s.length() - 1) {
                maxLength = max(maxLength, k * 2 - 1);
            }
        }
    }

    cout << maxLength << endl;
    return 0;
}



