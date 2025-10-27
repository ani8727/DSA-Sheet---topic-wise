// Longest Substring with atmost K distinct character

#include<iostream>
#include<unordered_map>
using namespace std;

// brute force approach
// int longSubstring(string s, int k){
//     int n=s.length();

//     int maxLength=0;
//     unordered_map<char,int> mp;
//     for(int i=0;i<n;i++){
//         mp.clear();
//         for(int j=i;j<n;j++){
//             mp[s[j]]++;
//             if(mp.size()>k){
//                 break;
//             }
//             maxLength=max(maxLength,j-i+1);
//         }
//     }
//     return maxLength;
// }

// better approach
// int longSubstring(string s, int k){
//     int n=s.length();

//     int maxLength=0;
//     unordered_map<char,int> mp;
//     int left=0;
//     for(int right=left;right<n;right++){
//         mp[s[right]]++;
//         while(mp.size()>k){
//             mp[s[left]]--;
//             if(mp[s[left]]==0) mp.erase(s[left]);
//             left++;
//         }
//         maxLength=max(maxLength,right-left+1);
//     }
//     return maxLength;
// }

// optimal approach approach
int longSubstring(string s, int k){
    int n=s.length();

    int maxLength=0;
    unordered_map<char,int> mp;
    int left=0, right=0;
    while(right<n){
        mp[s[right]]++;
        if(mp.size()>k){
            mp[s[left]]--;
            if(mp[s[left]]==0) mp.erase(s[left]);
            left++;
        }
        if(mp.size()<=k){
            maxLength=max(maxLength,right-left+1);
        }
        right++;
    }
    return maxLength;
}

int main(){
    string s="aaabbccd";
    int k=2;
    int ans=longSubstring(s,k);
    cout<<ans<<endl;
    return 0;
}