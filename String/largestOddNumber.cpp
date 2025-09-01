#include<iostream>
using namespace std;

class Solution{
    public:

    string largestNumber(string str){
         int n=str.length();
         for(int i=n-1;i>=0;i--){
            if((str[i]-'0')%2!=0){
                return str.substr(0,i+1); 
            }
         }
         return "";
    }
};

int main(){
    string str;
    cin>>str;

    Solution sol;

    string ans = sol.largestNumber(str);

    cout<<ans<<endl;

    return 0;
}