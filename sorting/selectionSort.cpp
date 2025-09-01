#include<iostream>
#include<vector>
using namespace std;

void sort(vector<int> &num){
    for(int i=0;i<num.size()-1;i++){
        int idx=i;
        for(int j=i+1;j<num.size();j++){
            if(num[j]<num[idx]){
                idx=j;
            }
        }
        int temp=num[idx];
        num[idx]=num[i];
        num[i]=temp;
    }
}
int main(){
    vector<int> num={4,2,8,1,9,0};

    sort(num);

    for(int i:num){
        cout<<i<<" ";
    }
    return 0;
}