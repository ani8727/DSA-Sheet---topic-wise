// Longest Longest Suubstring without repeating character

#include<iostream>
#include<unordered_map>
using namespace std;

int longestSubString(string s){
    int n=s.length();
    unordered_map<char,int>mp;
    int left=0, right=0, ans=0;
    while(right<n){
        char ch=s[right];
        if(mp.find(ch)!=mp.end()){
            left = max(left, mp[ch] + 1); // sayad already left cross kar gya ho to bas index change karna hai map ke ander
        }
        mp[ch]=right;
        ans=max(ans,right-left+1);
        cout<<ans<<endl;
        right++;
    }
    return ans;

}

int main(){
    string s="cadbzabcd";
    cout<<longestSubString(s)<<endl;
    return 0;
}