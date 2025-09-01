#include<iostream>
#include<vector>
#include<algorithm>
// calculate lowerBound of given number
using namespace std;

int lowerBound(vector<int> nums, int x){
    int lb =lower_bound(nums.begin(),nums.end(),x)-nums.begin();
    cout<<lb<<endl;
    int st=0;
    int end=nums.size();
    while(st<end){
        int mid=st+(end-st)/2;
        if(nums[mid]<x) st=mid+1;
        else end=mid;
    }
    return st;
}

// cal. lower bound of given numberkm
int upperBound(vector<int> nums ,int x){
    int ub= upper_bound(nums.begin(),nums.end(),x)-nums.begin();
    cout<<ub<<endl;
    int st=0;
    int end=nums.size();
    while(st<end){
        int mid =st+(end-st)/2;
        if(nums[mid]<=x) st=mid+1;
        else end=mid;
    }
    return st;
}
int main(){
    vector<int> nums={2,3,6,9,9,9};

    cout<<"LowerBound "<<lowerBound(nums,7)<<endl;;
    cout<<"UpperBound "<<upperBound(nums,4)<<endl;;
    return 0;
}