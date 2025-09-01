#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// int pivot(vector<int> nums){
    // int st=0, end=nums.size()-1, ans=INT_MAX;
    // while(st<=end){
    //     int mid=st+(end-st)/2;
    //     if(nums[st]<=nums[mid]){
    //         ans=min(ans,nums[st]);
    //         st=mid+1;
    //     }
    //      else {
    //         end=mid-1;
    //         ans=min(ans,nums[mid]);
    //      }
    // }
    // return ans;
// }

int pivot(vector<int> nums){
    int st=0, end=nums.size()-1;
    while(st<end){
      int mid=st+(end-st)/2;
      if(nums[mid]>nums[end]){
        st=mid+1;
      } else if(nums[mid]<nums[end]){
        end=mid;
      } else{
        end--;
      }
    }
    return st;
}
int main(){
    vector<int> nums={5,9,8,0,0,3,5};

    cout<<"Pivot: "<<pivot(nums)<<endl;
    return 0;
}