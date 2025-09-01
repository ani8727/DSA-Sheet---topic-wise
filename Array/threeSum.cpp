#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void twoSum(vector<int>& nums, int target, int i, int j, vector<vector<int>>& result){
    while(i < j){
        int sum = nums[i] + nums[j];
        if(sum > target){
            j--;
        } else if(sum < target){
            i++;
        } else {
            result.push_back({-target, nums[i], nums[j]});
            int lval = nums[i], rval = nums[j];
            while(i < j && nums[i] == lval) i++;
            while(i < j && nums[j] == rval) j--;
        }
    }
}

vector<vector<int>> threeSum(vector<int> nums, int target){
    int n = nums.size();
    vector<vector<int>> result;
    if(n < 3) return result;
    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int n1 = nums[i];
        int ans = target - n1;
        twoSum(nums, ans, i+1, n-1, result);
    }
    return result;
}

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    int target = 0;

    vector<vector<int>> ans = threeSum(nums, target);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j];
            if(j != ans[i].size() - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}