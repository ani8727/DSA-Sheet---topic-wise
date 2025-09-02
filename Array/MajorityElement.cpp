// 169. Majority Element - four different approach

#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

// 1. brute force appraoch -> t.c=n2

// int majority(vector<int> nums){
    
//     for(int val: nums){
//         int freq=0;

//         for(int ele: nums){
//             if(ele==val) freq++;
//         }
//         if(freq>nums.size()/2){
//             return val;
//         }
//     }
//     return -1;
// }

// 2. Optimal apprach - t.c =nlogn

// int majority(vector<int> nums){
//     sort(nums.begin(),nums.end());
//     int n=nums.size();
//     int freq=1;
//     int ans=nums[0];
//     for(int i=1;i<n;i++){
//         if(nums[i]==nums[i-1]){
//            freq++;
//         }else{
//             freq=1;
//             ans=nums[i];
//         }
//        if(freq>n/2){
//         return ans;
//        }
//     }
//    return ans;
// }

// 3. better appraoch - unorder_map

// int majority(vector<int> nums){
//    int n=nums.size();
//    unordered_map<int, int> mp;

//    for(int i=0;i<n;i++){
//     mp[nums[i]]++;
//    }

//    for(auto i: mp){
//     if(i.second>n/2){
//         return i.first;
//     }
//    }
//    return -1;
// }

// 4. optimal appraoch - moore's voting algorithm

int majority(vector<int> nums){
    int n=nums.size();
    int freq=0, ans=0;
    for(int i=0; i<n; i++){
        if(freq==0){
            ans=nums[i];
        }
        if(ans==nums[i]){
            freq++;
        }else {
            freq--;
        }
    }
    freq=0;
    for(int val:nums){
        if(val==ans){
            freq++;
        }
    }
    if(freq>n/2){
        return ans;
    }else {
        return -1;
    }
}
int main(){
    vector<int> nums={1,2,3,2,5,4,6,2,2,2,2,};
    cout<<majority(nums)<<endl;
    return 0;
}