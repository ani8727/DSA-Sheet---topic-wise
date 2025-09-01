#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//            Two Sum -2 - Array is sorted ->Leetcode-167

vector<int> twoSum(vector<int> nums, int target){
    int n=nums.size();
    int st=0, end=n-1;
    while(st<end){
        if(nums[st]+nums[end]==target){
            return{st+1, end+1};
        }else if(nums[st]+nums[end]<target){
            st++;
        }else{
            end--;
        }
    }
    return {};
}
// if output wants all two sum value in vector without diplicity 

vector<vector<int>> twoSum2(vector<int> nums, int target){

       vector<vector<int>> ans;
       int n=nums.size();
       int left=0, right=n-1;
       while(left<right){
            if(nums[left]+nums[right]==target){
                while(left<right && nums[left]==nums[left+1]){
                    left++;
                }
                while(left<right && nums[right]==nums[right-1]){
                    right--;
                }
            ans.push_back({nums[left],nums[right]});
            left++;
            right--;
        }
        else if(nums[left]+nums[right]<target){
            left++;
        }else {
            right--;
        }
       }
       return ans;
}
int main(){
    vector<int> nums ={-1,0,1,2,-1,-4};
  sort(nums.begin(), nums.end());

    int target=0;

    vector<int> ans =twoSum(nums, target);

    // cout<<"Indices: "<<ans[0]<<","<<ans[1]<<endl;

    vector<vector<int>> result = twoSum2(nums,  target);

    for(int i = 0; i < result.size(); i++) {
    cout << "[";
    for(int j = 0; j < result[i].size(); j++) {
        cout << result[i][j];
        if(j != result[i].size() - 1) cout << ",";
    }
    cout << "]" << endl;
    }

    return 0;
}