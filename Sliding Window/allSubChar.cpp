#include<iostream>
#include<vector>
using namespace std;

vector<string> subChar(string s){
    int n=s.length();
    vector<string> ans;
    for(int i=0;i<n;i++){
        string str;
        for(int j=i;j<n;j++){
            str+=s[j];
            ans.push_back(str);
        }
    }
    return ans;
}

int main(){
    string s="abczdbac";
    vector<string> ans= subChar(s);
    for(string str: ans){
        cout<<str<<endl;
    }
    return 0;
}