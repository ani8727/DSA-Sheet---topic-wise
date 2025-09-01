#include<iostream>
#include<vector>

using namespace std;

int pivot(vector<int>& nums){
    int st=0;
    int end=nums.size()-1;
    if(nums[st]<=nums[end]) return 0;
    while(st<end){
        int mid=st+(end-st)/2;
        if(nums[mid]>nums[end]) st=mid+1;
        else end=mid;
    }
    return st;
}
int search(vector<int>& nums, int st, int end, int x){
    while(st<end){
        int mid=st+(end-st)/2;
        if(nums[mid]<x) st=mid+1;
        else end=mid;
    }
    return ((nums[st]==x)?st:-1);
}
int Bsearch(vector<int>& nums, int x){
    int pvt=pivot(nums);
    if(x>=nums[pvt] && x<=nums[nums.size()-1]){
        return search(nums,pvt,nums.size()-1,x);
    } else {
        return search(nums,0,pvt-1,x);
    }
}
int main(){
    vector<int> nums={9,8,7,2,3,5};

    cout<<Bsearch(nums,6);
    return 0;
}