// 930. Binary Subarrays With Sum

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// brute force approach - LTE
// int maxSubarray(vector<int> nums, int goal){
//     int n=nums.size();
//     int ans=0;

//     for(int i=0;i<n;i++){
//         int sum=0;
//         for(int j=i;j<n;j++){
//             sum+=nums[j];
//             if(sum==goal) ans++;
//         }
//     }
//     return ans;
// }

// optimal approach- prefix and hashing
int maxSubarray(vector<int> nums, int goal){
    unordered_map<int, int> prefixCount;
    prefixCount[0]=1;

    int prefixSum=0, count=0;

    for(int num: nums){
        prefixSum+=num;
        if(prefixCount.find(prefixSum-goal)!=prefixCount.end()){
            count+=prefixCount[prefixSum-goal];
        }
        prefixCount[prefixSum]++;
    }
    return count;
}

int main(){
    vector<int> nums={1,0,1,0,1};
    int goal=2;

    int ans=maxSubarray(nums, goal);
    
    cout<<ans<<endl;

    return 0;
}