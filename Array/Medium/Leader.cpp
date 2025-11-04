// Leaders in an Array

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

// Brute force approach
// vector<int> searchLeader(vector<int>nums){
//     vector<int> leaders;
//     for(int i=0;i<nums.size();i++){
//         bool leader=true;
//         for(int j=i;j<nums.size();j++){
//             if(nums[j]>nums[i]){
//                 leader=false;
//                 break;
//             }
//         }
//         if(leader) leaders.push_back(nums[i]);
//     }
//     return leaders; 
// }

// using two pointer
vector<int> searchLeader(vector<int> nums) {
    vector<int> leaders;
    int n = nums.size();
    // Start from the last element — always a leader
    int maxRight = nums[n - 1];
    leaders.push_back(maxRight);
    // Traverse from right to left
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] >= maxRight) {
            maxRight = nums[i];
            leaders.push_back(nums[i]);
        }
    }
    // Reverse to maintain the original order
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main(){
    vector<int> nums={10,22,12,3,0,6};

    vector<int>leaders=searchLeader(nums);

    for(int leader: leaders){
        cout<<leader<<" ";
    }
    return 0;
}