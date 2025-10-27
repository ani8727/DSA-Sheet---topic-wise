// 1358. Number of Substrings Containing All Three Characters

#include<iostream>
#include<unordered_set>
using namespace std;

// brute force approach
int subString(string s){
    int n=s.length();
    unordered_set<char> st;
    int ans=0;
    for(int i=0;i<n;i++){
        st.clear();
        for(int j=i;j<n;j++){
            st.insert(s[j]);
            if(st.size()>=3) ans++;
        }
    }
    return ans;
}

//better approach

int main(){
    string s="abcabc";
    
    int ans=subString(s);

    cout<<ans<<endl;

    return 0;
}