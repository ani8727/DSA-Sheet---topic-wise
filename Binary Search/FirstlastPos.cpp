// find last and first postion of element in sorted array
#include<iostream>
#include<vector>

using namespace std;
// brute force approach
/*
int first(vector<int> nums,int target){
    for(int i=0;i<nums.size();i++){
        if(nums[i]==target)
          return i;
    }
    return -1;
}
int last(vector<int> nums, int target){
    for(int i=nums.size()-1;i>=0;i--){
        if(nums[i]==target)
            return i;
    }
    return -1;
}
*/

//optimal approach using binary search

int first(vector<int> nums, int target){
    int st=0;
    int end=nums.size()-1;
    int ans=-1;
    while(st<=end){
       int mid=st+(end-st)/2;
       if(nums[mid]==target){
        ans=mid;
        end=mid-1;
       }
       else if(nums[mid]>target){
        end=mid-1;
       }
       else{
        st=mid+1;
       }
    }
    return ans;
}
int last(vector<int> nums, int target){
    int st=0;
    int end=nums.size()-1;
    int ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(nums[mid]==target){
            ans=mid;
            st=mid+1;
        }
        else if(nums[mid]>target){
            end=mid-1;
        }
        else{
            st=mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> nums={3,7,7,8,8,9};
     
    cout<<"first: "<<first(nums,8)<<" ";
    cout<<"last: "<<last(nums,8)<<endl;

    
    return 0;
}