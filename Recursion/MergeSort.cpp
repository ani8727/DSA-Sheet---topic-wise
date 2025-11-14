//  Merge sort using Recursion
#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& nums, int st, int mid, int end){
    int n1=mid+1-st;
    int n2=end-mid;

    vector<int> num1(n1);
    vector<int> num2(n2);

    int k=st;

    for(int i=0;i<n1;i++){
        num1[i]=nums[k++];
    }
    for(int i=0;i<n2;i++){
        num2[i]=nums[k++];
    }
    int i=0, j=0;
    k=st;
    while(i<n1 && j<n2){
        if(num1[i]<num2[j]){
            nums[k++]=num1[i++];
        }else{
            nums[k++]=num2[j++];
        }
    }
    while(i<n1){
        nums[k++]=num1[i++];
    }
    while(j<n2){
        nums[k++]=num2[j++];
    }
}
void sort(vector<int>& nums, int st, int end){
    if(st>=end)
        return;
    int mid=st+(end-st)/2;
    
    sort(nums,st,mid);
    sort(nums,mid+1,end);

    merge(nums,st,mid,end);

}

int main(){
    vector<int> nums={1,4,2,6,8,9,5,1};

    int n=nums.size();

    sort(nums,0,n-1);

    for(int num: nums){
        cout<<num<<" ";
    }
    return 0;
}