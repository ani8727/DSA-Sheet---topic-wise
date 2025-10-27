// Max Consecutive Ones III

#include<iostream>
#include<vector>
using namespace std;

int maxiOne(const vector<int>& nums, int k) {
    int n = nums.size();
    int left = 0, right = 0;
    int zeros = 0, ans = 0;

    while(right < n) {
        // Count zero at current position
        if(nums[right] == 0) {
            zeros++;
        }
        
        // Shrink window if too many zeros
        while(zeros > k) {
            if(nums[left] == 0) {
                zeros--;
            }
            left++;
        }
        
        // Update maximum length
        ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}

int main(){
    vector<int> nums={1,1,1,0,0,0,1,1,1,1,0};
    int k=2;
    int ans=maxiOne(nums,k);

    cout<<ans<<endl;

    return 0;
}