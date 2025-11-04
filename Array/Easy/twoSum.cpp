#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
            //  TwoSum - leetcode -1

            //Brute-force approach 
// vector<int> twoSum (vector<int> nums, int target){
//     for(int i=0;i<nums.size()-1;i++){
//         for(int j=i+1;j<nums.size();j++){
//             if(nums[i]+nums[j]==target){
//               return {nums[i],nums[j]};
//             }
//         }
//     }
// }

//  Optimal appraoch using map

vector<int> twoSum(vector<int> nums, int target){
    unordered_map<int, int> mp;
    int n=nums.size();

    for(int i=0;i<n;i++){
        int secondDigit=target-nums[i]; // second digit

        if(mp.count(secondDigit)){
           return {mp[secondDigit],i};
        }
        mp[nums[i]]=i;
    }
    return {};
}

int main(){
 vector<int> nums ={3, 4,9,2};
   
   vector<int> ans = twoSum(nums,6);
   cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}

