// 136. Single Number
// You must implement a solution with a linear runtime complexity and use only constant extra space.

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums={4,1,2,1,2};

    // we can use bit manipulation - xor bit

    int xorr=0;
    for(int num: nums){
        xorr^=num; // all each 0 only single remain - xorr=4^4=0 
    }
    cout<<xorr;
    return 0;
}