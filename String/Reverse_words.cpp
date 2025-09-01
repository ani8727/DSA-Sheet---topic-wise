#include <iostream>
using namespace std;

class Solution {
public:
    string reverse(string s) {
        int n = s.length();
        string ans = "";
        int i = n - 1;

        while (i >= 0) {
            while (i >= 0 && s[i] == ' ') {
                i--;
            }

            string word = "";
            while (i >= 0 && s[i] != ' ') {
                word = s[i] + word;
                i--;
            }

            if (!word.empty()) {
                if (!ans.empty()) {
                    ans += ' ';
                }
                ans += word;
            }
        }

        return ans;
    }
};

int main() {
    string s = "The Sky is Blue";

    Solution sol;
    string result = sol.reverse(s);

    cout << "Reversed words: " << result << endl;

    return 0;
}
