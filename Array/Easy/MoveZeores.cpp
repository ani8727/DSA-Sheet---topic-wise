// 283. Move Zeroes . InPlace not be used extra space

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums={1,0,3,12};

    int left=0;
    int right=0;
    while(right<nums.size()){
        if(nums[right]!=0){
            swap(nums[left],nums[right]);
            left++;
        }
        right++;
    }
    
    for(int num: nums){
        cout<<num<<" ";
    }
    return 0;
}
