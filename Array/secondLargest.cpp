#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// brute force
// int secondLargest(vector<int>& nums){
//     sort(nums.begin(),nums.end());
    
//     int largest = nums[nums.size()-1];
//     for(int i=nums.size()-2;i>=0;i--){
//         if(nums[i]!=largest) return nums[i];
//     }
//     return largest;
// }

// better appraoch

int secondLargest(vector<int>& nums){
    int largest =INT_MIN;
    int sLargest=INT_MIN;

    for(int i=0;i<nums.size();i++){
        if(nums[i]>largest){
            sLargest=largest;
            largest=nums[i];  
        }else if(nums[i]<largest && nums[i]>sLargest){
                sLargest=nums[i];
        }
    }
    return (sLargest==INT_MIN)? -1:sLargest;
}

int main(){
    vector<int> nums ={1,2,4,7,7,5};

    int ans = secondLargest(nums);

    cout<<"Second Largest Number: "<<ans<<endl;
    return 0;
}