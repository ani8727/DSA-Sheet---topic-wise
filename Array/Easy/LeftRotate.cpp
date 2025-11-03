// 189. Rotate Array

// Left Rotate|| front-back -> we have to anti-clock direction

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Brute force approach - using extra storage
// void rotate(vector<int>& nums, int d){
//     int n=nums.size();
//     if (n == 0) return;
//     d%=n;
//     if (d == 0) return;
//     vector<int> temp(d);
//     // store first d element those move to back after rotating
//     for(int i=0;i<d;i++){
//         temp[i]=nums[i];
//     }
//     // move to first index those after d element
//     for(int i=d;i<n;i++){
//         nums[i-d]=nums[i];
//     }
//     // now add back those top d element store
//     for(int i=0;i<d;i++){
//         nums[n-d+i]=temp[i];
//     }
// }

// better approach - step by step rotate
// void rotate(vector<int>& nums, int d){
//     int n=nums.size();
//     if (n == 0) return;
//     d%=n;
//     if (d == 0) return;
//     for(int i=1;i<=d;i++){
//         int first=nums[0];
//         for(int j=0;j<n-1;j++){// it stop after n-2 index
//             nums[j]=nums[j+1];
//         }
//         nums[n-1]=first; // jo rah gya tha yha se kar dena
//     }
// }

// optimal appraoch - reverse method
void rotate(vector<int>& nums, int d){
    int n=nums.size();
    if (n == 0) return;
    d%=n;
    if (d == 0) return;
/*
    // first reverse d element - 0 to d-1
    reverse(nums.begin(),nums.begin()+d);
    // then resvse remaing n-d -> d to n-1
    reverse(nums.begin()+d,nums.end());
    // after reverse while array to arrnage them 
    reverse(nums.begin(),nums.end());
*/
    // make own function - lamda function
    auto reverseFunct = [](vector<int>& nums, int left, int right) {
        while(left<right){
            swap(nums[left++],nums[right--]);
        }
    };

    reverseFunct(nums,0,d-1);
    reverseFunct(nums,d,n-1);
    reverseFunct(nums,0,n-1);

}

int main(){
    vector<int> nums={1,2,3,4,5,6,7,};
    int d=10; // times rotate

    rotate(nums,d);

    for(int num: nums){
        cout<<num<<" ";
    }cout<<endl;
    return 0;
}
