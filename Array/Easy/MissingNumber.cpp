// 268. Missing Number
// Given an array containing n distinct numbers taken from [0, n],

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Brute Force Approach (Using Sorting + Binary Search)
/*
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    sort(begin(nums), end(nums)); // O(n log n)
    int ans = n;
    int l = 0, r = n - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] > mid) {
            ans = mid;  // potential missing index
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}
*/
// Better Approach (Using Sum Formula)
/*
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int expectedSum = (n * (n + 1)) / 2; // sum of 0..n
    int actualSum = 0;

    for (int i : nums) {
        actualSum += i;
    }
    return expectedSum - actualSum;
}
*/
// Optimal Approach (Using XOR)
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int xor1 = 0, xor2 = 0;

    for (int i = 0; i <= n; i++) {
        xor1 ^= i;        // XOR of 0 to n
    }
    for (int i : nums) {
        xor2 ^= i;        // XOR of array
    }
    return xor1 ^ xor2;   // missing number
}

int main() {
    vector<int> nums = {3, 0, 1};
    cout << "Missing Number: " << missingNumber(nums) << endl;
    return 0;
}
