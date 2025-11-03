// 485. Max Consecutive Ones
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums={0,0};

    int cnt=0;
    int maxCount=0;
    for(int num: nums){
        if(num==1) cnt++;
        else cnt=0;
        maxCount=max(maxCount,cnt);
    }
    cout<<"Consecutivr one: "<<maxCount<<endl;

    return 0;
}