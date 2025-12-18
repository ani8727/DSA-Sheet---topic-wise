// 1832. Check if the Sentence Is Pangram

#include<iostream>
#include<vector>
using namespace std;

bool pangram(string s){
    int n=s.length();
    if(n<26) return false;
    vector<int>count(26,0);

    for(char ch: s){
        count[ch-'a']++;
    }
    for(int cnt: count){
        if(cnt<1) return false;
    }
    return true;
}

int main(){
    string s="thequickbrownfoxjumpsoverthelazydog";
    string s2="Leetcode";

    if(pangram(s1))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
        
    return 0;
}