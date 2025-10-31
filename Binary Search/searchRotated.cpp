// 33. Search in Rotated Sorted Array

#include<iostream>
#include<vector>
using namespace std;

// find lowest or pivot elemnt in rotated sorted array
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
    while(st <= end){
        int mid = st + (end - st) / 2;
        if(nums[mid] == x) return mid;
        else if(nums[mid] < x) st = mid + 1;
        else end = mid - 1;
    }
    return -1;
}
int Bsearch(vector<int>& nums, int x){
    int pvt=pivot(nums);
    if(x>=nums[pvt] && x<=nums[nums.size()-1]){
        return search(nums,pvt,nums.size()-1,x);
    } else {
        return search(nums,0,pvt-1,x);
    }
}

// second approach

int searchSorted(vector<int>nums, int x){
    int st=0, end=nums.size()-1;

    while(st<=end){
        int mid=st+(end-st)/2;

        if(nums[mid]==x) return mid;

        if(nums[st]<=nums[mid]){ //left part sorted
            if(x>=nums[st] && x<=nums[mid]) // search in left part
                end=mid-1;
            else // search in right part
                st=mid+1;
        } else{  //right part sorted
            if(x>=nums[mid] && x<=nums[end]) // search in right part
                st=mid+1;
            else // search in left part
                end=mid-1;    
        }        
    }
    return -1;
}
int main(){
    vector<int> nums={9,8,7,2,3,5};

    cout<<Bsearch(nums,4);
    cout<<endl;
    cout<<searchSorted(nums,4);

    return 0;
}