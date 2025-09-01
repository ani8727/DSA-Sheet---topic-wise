#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
    public: 
       bool isomorphic(string str1, string str2){
         unordered_map<char,char> mp1;
         unordered_map<char, char> mp2;

         for(int i=0; i<str1.length();i++){
            char ch1=str1[i];
            char ch2=str2[i];

            if(mp1.find(ch1)!=mp1.end() && mp1[ch1]!=ch2 ||
               mp2.find(ch2)!=mp2.end() && mp2[ch2]!=ch1){
                return false;
               }
            mp1[ch1]=ch2;
            mp2[ch2]=ch1;   
         }
         return true;
       }
};

int main(){
    string str1="egg";
    string str2="ram";

    Solution sol;

    bool isTrue = sol.isomorphic(str1,str2);

    cout<<isTrue<<endl;
    return 0;
}