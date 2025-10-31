#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// calculate lowerBound of given number
// int lowerBound(vector<int> nums, int x){
//     int lb =lower_bound(nums.begin(),nums.end(),x)-nums.begin();
//     cout<<lb<<endl;
//     int st=0;
//     int end=nums.size();
//     while(st<end){
//         int mid=st+(end-st)/2;
//         if(nums[mid]<x) st=mid+1;
//         else end=mid;
//     }
//     return st;
// }
// 2nd appraoch
int lowerBound(vector<int> nums, int x){
    int st=0, end=nums.size()-1;
    int ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(nums[mid]>=x){
            ans=mid;
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    return ans;
}

// cal. upper bound of given numberkm
// int upperBound(vector<int> nums ,int x){
//     int ub= upper_bound(nums.begin(),nums.end(),x)-nums.begin();
//     cout<<ub<<endl;
//     int st=0;
//     int end=nums.size();
//     while(st<end){
//         int mid =st+(end-st)/2;
//         if(nums[mid]<=x) st=mid+1;
//         else end=mid;
//     }
//     return st;
// }
// 2nd appraoch
int upperBound(vector<int> nums, int x){
    int st=0, end=nums.size()-1;
    int ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(nums[mid]>x){
            ans=mid;
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> nums={2,3,6,9,9,9};

    cout<<"LowerBound "<<lowerBound(nums,8)<<endl;;
    cout<<"UpperBound "<<upperBound(nums,3)<<endl;;
    return 0;
}