#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums = {3,3,0,99,-40};
    int largest=nums[0];
    for(int &i: nums){
        if(largest<i) largest=i;
    } cout<<largest;
    return 0;
}