#include<iostream>
#include<vector>

using namespace std;

// cal if x is present then return element if not then inserted pos

int InsertPos(vector<int>& nums, int x){
    int st=0;
    int end=nums.size();
    while(st<end){
        int mid=st+(end-st)/2;
        if(nums[mid]==x) return mid;
        if(nums[mid]<x) st=mid+1;
        else end=mid;
    }
    return st;
}
// lowerBound code is same for this problem
int main(){
    vector<int> nums={2,3,4,4,6,8,9};
    cout<<"inserted Pos: "<<InsertPos(nums,5)<<endl;;
    return 0;   
}