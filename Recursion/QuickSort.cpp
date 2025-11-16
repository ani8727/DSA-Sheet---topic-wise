//  Quick Sort using recursion

#include<iostream>
#include<vector>
using namespace std;

int pivotEle(vector<int>& nums, int st, int end){
    int pivot=nums[end];
    int pi=st;
    for(int i=st;i<end;i++){
        if(nums[i]<=pivot){
            swap(nums[i],nums[pi]);
            pi++;
        }
    }
    swap(nums[end],nums[pi]);
    return pi;
}

void sort(vector<int>& nums, int st, int end){
    if(st>=end)
        return;
    int pi=pivotEle(nums,st,end);

    sort(nums,st,pi-1);
    sort(nums,pi+1,end);
}

void quickSort(vector<int>& nums){
    int n=nums.size();
    if(n<=1)
        return;
    
    sort(nums,0,n-1);
}

int main(){
    vector<int> nums={2,1,8,9,0,1,5,3,2};

    quickSort(nums);

    for(int num: nums){
        cout<<num<<" ";
    }cout<<endl;

    return 0;
}