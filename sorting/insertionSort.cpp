#include<iostream>
#include<vector>
using namespace std;

void sort(vector<int> &num){
    for(int i=1;i<num.size();i++){
        int curr=num[i];
        int prev=i-1;
        while(prev>=0 && num[prev]>curr){
            num[prev+1]=num[prev];
            prev--;
        }
        num[prev+1]=curr;
    }
}
int main(){
    vector<int> num={3,6,2,1,0,9};

    sort(num);

    for(int i: num){
        cout<<i<<" ";
    }
    return 0;
}