#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{

public:
    string prefix(vector<string>& strs)
    {
        string ans = "";
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string first = strs[0];
        string last = strs[n - 1];
        for (int i = 0; i < min(first.length(), last.length()); i++)
        {
            if (first[i] != last[i])
            {
                return ans;
            }
            else
            {
                ans += first[i];
            }
        }
        return ans;
    }
};

int main()
{
    vector<string> strs = {"flower", "ram", "flight"};

    Solution sol;

    string ans = sol.prefix(strs);

    cout << ans << endl;

    for(string str: strs){
        cout<<str<<" ";
    }cout<<endl;

    return 0;
}
