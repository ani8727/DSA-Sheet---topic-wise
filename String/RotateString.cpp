// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

// A shift on s consists of moving the leftmost character of s to the rightmost position.

#include<iostream>
#include<algorithm>

using namespace std;

class Solution{
    public:
      bool isTrue(string s, string goal){
        int n=s.length();
        int m=goal.length();

        if(n!=m) return false;

        // for(int i=0;i<n;i++){
        //   if(s==goal) return true;
        //   rotate(goal.begin(),goal.begin()+1,goal.end());
        // }

        if((s+s).find(goal)!=string::npos){
            return true;
        }
        return false;
      }
}; 

int main(){
    string s="abcde";
    string goal= "bcdea";

    Solution sol;

    cout<<sol.isTrue(s, goal)<<endl;

    return 0;
}