#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() - 1;
        
        while (st <= end) {
            int mid = st + (end - st) / 2;
            
            // Found target
            if (nums[mid] == target) {
                return true;
            }
            
            // Handle duplicates at the start
            if (nums[st] == nums[mid]) {
                st++;
                continue;
            }
            
            // Left half is sorted
            if (nums[st] <= nums[mid]) {
                if (nums[st] <= target && target < nums[mid]) {
                    end = mid - 1;  // Target in left half
                } else {
                    st = mid + 1;   // Target in right half
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[end]) {
                    st = mid + 1;   // Target in right half
                } else {
                    end = mid - 1;  // Target in left half
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 0;
    
    cout << "Found target: " << (sol.search(nums, target) ? "true" : "false") << endl;
    return 0;
}