// Counting bit - n+1 size ke idex ka bit 1 cal.

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> ans(n+1,0);

    for(int i=1;i<=n;i++){
        ans[i]=cal(i);
    }
    for(int i: ans){
        cout<<i<<" ";
    }
    return 0;   
}