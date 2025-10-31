// Count Occurrences in Sorted Array

#include<iostream>
#include<vector>
using namespace std;

// First Occurences
int firstOcc(vector<int> nums, int x){
    int st=0, end=nums.size();
    while(st<end){
        int mid=st+(end-st)/2;
        if(nums[mid]<x){
            st=mid+1;
        }else{
            end=mid;
        }
    }
    return st;
}
// last Occurences
int lastOcc(vector<int> nums, int x) {
    int st = 0, end = nums.size();
    while (st < end) {
        int mid = st + (end - st) / 2;
        if (nums[mid] <= x)
            st = mid + 1; 
        else
            end = mid;
    }
    return st - 1;         
}


int main(){
    vector<int> nums={1,1,2,2,2,2,2,3};

    int x=2;

    int fisrt_idx=firstOcc(nums,x);
    int last_idx=lastOcc(nums,x);

    int totalocc=last_idx-fisrt_idx+1;

    cout<<totalocc<<endl;

    return 0;

}