#include<iostream>
using namespace std;

int maxV(string s, int k){
    int i=0;
    int j=0;
    int count=0;
    int maxcount=0;

    // lemda function to check vowels
    auto isVowel=[&](char c){
        char l=tolower(c);
        return l=='a'||l=='e'||l=='i'||l=='o'||l=='u';
    };
    while(j<s.length()){
        if(isVowel(s[j])){
            count++;
        }
        if(j-i+1==k){
            maxcount=max(maxcount,count);
            if(isVowel(s[i])){
                count--;
            }
            i++;
        }
        j++;
    }
    return maxcount;
}
int main(){
    string s="leetcode";
    cout<<"Max Vowels: "<<maxV(s,3)<<endl;
    return 0;
}