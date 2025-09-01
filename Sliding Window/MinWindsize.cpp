//Minmum wsindow substring-> 76
#include<iostream>
#include<unordered_map>
#include<climits>

using namespace std;

string minWind(string s, string t){
    int n=s.length();
    int m=t.length();

    if(m>n) return "";

    unordered_map<char, int> mp;
    for(char& ch: t){
        mp[ch]++;
    }

    int Rcount=m;
    int i=0, j=0;

    int winSize=INT_MAX;
    int start_i=0;

    while(j<n){
        char ch=s[j];

        if(mp[ch]>0)
            Rcount--;

        mp[ch]--;

        while(Rcount==0){
            winSize=min(winSize,j-i+1);
            start_i=i;

            mp[s[i]]++;

            if(mp[s[i]]>0)
               Rcount++;
            i++;
        }
        j++;
    }
    return winSize==INT_MAX ? "" : s.substr(start_i,winSize);   
}
int main(){
    string s="ADOBECODEBANC";
    string t="ABC";

    cout<<"Minimum Substring : "<<minWind(s,t)<<endl;
    return 0;
}