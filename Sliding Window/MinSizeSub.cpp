#include<iostream>
#include<vector>

using namespace std;

int minSub(vector<int> nums,int target){
    int left=0;
    int right=0;
    int sum=0;
    int minl=nums.size();
    while(right<nums.size()){
         sum+=nums[right];
        while(sum>=target){
            minl=min(minl,right-left+1);
            sum-=nums[left];
            left++;
         }
         right++;
    }
    return minl;
}
int main(){
    vector<int> nums={2,3,1,2,4,3};

    cout<<"Minimum size of subarray: "<<minSub(nums,7)<<endl;
    return 0;
}