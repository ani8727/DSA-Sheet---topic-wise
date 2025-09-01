#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:
    bool isAnagram(string str1, string str2)
    {
        int n = str1.length();
        int m = str2.length();

        if (n != m) return false;

        vector<int> s(26,0);

        for(char ch: str1){
            s[ch-'a']++;
        }
        for(char ch: str2){
            s[ch-'a']--;
        }
        // for(int i: s){
        //     if(i!=0) return false; 
        // }
        // lamds function
        bool allZero= all_of(s.begin(),s.end(),[](int element){
             return element==0;
        });
        return true;    
    }
};
int main()
{
    string str1 = "anagram";
    string str2 = "anarmga";

    Solution sol;

    cout<<sol.isAnagram(str1,str2)<<endl;

    return 0;
}