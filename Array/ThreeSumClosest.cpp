#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;
// brute force appraoch

// int threeSum(vector<int> nums, int target){
//     int minDiff=INT_MAX;
//     int closestSum=0;
//     int n=nums.size();
//     for(int i=0;i<n-2;i++){
//         for(int j=i+1;j<n-1;j++){
//             for(int k=j+1;k<n;k++){
//                 int currentSum=nums[i]+nums[j]+nums[k];
//                 int diff=abs(target-currentSum);
//                 if(diff<minDiff){
//                      minDiff=diff;
//                      closestSum= currentSum;
//                 } 
//             }
//         }
//     }
//     return closestSum;
// }

int threeSum (vector<int> nums, int target){
    int n=nums.size();
    sort(nums.begin(), nums.end());
    int minDiff=INT_MAX;
    int closestSum=0;
    for(int i=0;i<n-2;i++){
        int left=i+1;
        int right=n-1;
        while(left<right){
            int currentSum=nums[i]+nums[left]+nums[right];
            int diff=abs(target-currentSum);
            if(diff<minDiff){
                minDiff=diff;
                closestSum=currentSum;
            }

            if(currentSum<target){
                left++;
            }
            else if(currentSum>target){
                right--;
            }else {
                return closestSum;
            }
        }
    }
    return closestSum;
}
int main(){
    vector<int> nums= {-1, 2, 1, 4};
    int target =1;
    int ans= threeSum(nums,target);
    cout<<ans;
    return 0;

}