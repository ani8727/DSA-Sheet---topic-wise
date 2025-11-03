// 410. Split Array Largest Sum

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int split(vector<int>nums, int sum){
    int subarray=1;
    int totalSum=0;
    for(int num: nums){
        if(totalSum+num<=sum){
            totalSum+=num;
        }else{
            subarray++;
            totalSum=num;
        }
    }
    return subarray;
}

int splitArray(vector<int>nums, int k){
    int n=nums.size();
    
    int st=*max_element(nums.begin(),nums.end());
    int end=accumulate(nums.begin(),nums.end(),0);

    // for(int i=st;i<=end;i++){
    //     int subArray=split(nums,i);
    //     if(subArray==k) return i;
    // }

    while(st<=end){
        int mid=st+(end-st)/2;
        int subarray=split(nums,mid);
        if(subarray>k) st=mid+1;
        else end=mid-1;
    }
    return st;
}

int main(){
    vector<int> nums={1,2,3,4,5};
    int k=2;

    cout<<"Largest Sum of Minimum Split Subarray: "<<splitArray(nums,k)<<endl;
    return 0;
}