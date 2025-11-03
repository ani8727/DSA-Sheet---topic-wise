// 189. Rotate Array

// Right Rotate || back-front -> we have to clock direction

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
//     // store first d element those move to first after rotating
//     for(int i=n-d;i<n;i++){ // element from back
//         temp[i+d-n]=nums[i]; // at 0 index -> 4+3-7=0
//     }
//     // move to last index those before d element just leave on d place 
//     for(int i=n-d-1;i>=0;i--){  // 3-2-1-0
//         nums[i+d]=nums[i]; // shift to afte d places - 3+3, 2+3, 1+3, 0+3 
//     }
//     // now add back those back d element store
//     for(int i=0;i<d;i++){
//         nums[i]=temp[i];  // we have to add on a top d places
//     }
// }

// better approach - step by step rotate
// void rotate(vector<int>& nums, int d){
//     int n=nums.size();
//     if (n == 0) return;
//     d%=n;
//     if (d == 0) return;
//     for(int i=1;i<=d;i++){
//         int last=nums[n-1]; 
//         for(int j=n-1;j>0;j--){// it start to last index at 2nd index
//             nums[j]=nums[j-1];
//         }
//         nums[0]=last; // jo rah gya tha yha se kar dena
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
    reverse(nums.end()-d,nums.end());
    // then resvse remaing n-d -> d to n-1
    reverse(nums.begin(),nums.end()-d);
    // after reverse while array to arrnage them 
    reverse(nums.begin(),nums.end());
*/
    // make own function - lamda function
    auto reverseFunct = [](vector<int>& nums, int left, int right) {
        while(left<right){
            swap(nums[left++],nums[right--]);
        }
    };

    reverseFunct(nums,n-d,n-1);
    reverseFunct(nums,0,n-d-1);
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
