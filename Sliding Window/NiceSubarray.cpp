// 1248. Count Number of Nice Subarrays

#include<iostream>
#include<vector>
using namespace std;

int niceSubarray(vector<int> nums, int k){
    int n=nums.size();

    int ans=0;
    for(int i=0;i<n;i++){
        int odd=0;
        for (int j = i; j < n; j++) {
            if (nums[j] % 2 != 0) odd++;
            if (odd == k) ans++;
            if (odd > k) break;
        }
    }
    return ans;
}

int main(){
    vector<int> nums={2,2,2,1,2,2,1,2,2,2};
    int k=2;

    int ans=niceSubarray(nums, k);
    cout<<ans<<endl;
    return 0;
}