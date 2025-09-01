// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
          string sort(string str){
            vector<int> s(26,0);
            for(char ch: str){
                s[ch-'a']++;
            }
            string ans="";
            for(int i=0;i<26;i++){
                if(s[i]>0){
                    ans.append(s[i],'a'+i);
                }
            }
            return ans;
          }
};
int main(){
    string str="cccaaa";

    Solution sol;

    string ans=sol.sort(str);
    cout<<ans<<endl;
    return 0;
}