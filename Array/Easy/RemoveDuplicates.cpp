// 26. Remove Duplicates from Sorted Array
// reutn array of unique element must be first place after that not be check

#include<iostream>
#include<vector>
using namespace std;

// using two pointer
void removeDup(vector<int>& nums){
    int left=0;
    int right=1;
    while(right<nums.size()){
        if(nums[left]!=nums[right]){
            left++;
            nums[left]=nums[right];   
        }
        right++;
    }
}

int main(){
    vector<int> nums={1,1,2,3,3,3,4,4};

    removeDup(nums);

    cout<<"After Removing from first places"<<endl;
    for(int num: nums){
        cout<<num<<" ";
    }
    return 0;    
}