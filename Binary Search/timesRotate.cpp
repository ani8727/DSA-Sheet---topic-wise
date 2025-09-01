#include<iostream>
#include<vector>
// How many time rotate the array
using namespace std;

int rotate(vector<int> nums){
    int st=0;
    int end=nums.size()-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(nums[mid]>nums[end]){
            st=mid+1;
        }
        else if(nums[mid]<nums[end]){
            end=mid;
        }else{
           end--;
        }
    }
    return st;
}
int main(){
    vector<int> nums={4,6,7,1,2,2};
    cout<<"No. pf time rotate: "<<rotate(nums)<<endl;
    return 0;
}