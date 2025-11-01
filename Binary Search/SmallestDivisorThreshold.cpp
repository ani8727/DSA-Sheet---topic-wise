// 1283. Find the Smallest Divisor Given a Threshold

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

// calculate smaller divisor
// int cal(vector<int>nums,int threshold, int divisor){
//     int total=0;
//      for(int j=0;j<nums.size();j++){
//                 total+=ceil((double)nums[j]/divisor);
//                 cout<<total<<" ";
//             }
//     if(total<=threshold) return  divisor;
//     else return -1;
// }
// // brute force approach
// int smallestDivisor(vector<int>& nums, int threshold) {
//         int n=nums.size();
//         int last=*max_element(nums.begin(),nums.end());

//         for(int i=1;i<=last;i++){
//             cout<<i <<" ";
//             if(cal(nums,threshold,i)>0){
//                 return i;
//             }
//         }
//         return -1;     
//     }

// optimal approach - log n

int cal(vector<int>nums, int divisor){
        int total=0;
        for(int j=0;j<nums.size();j++){
            total+=ceil((double)nums[j]/divisor);
        }
        return total;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int st=1;
        int end=*max_element(nums.begin(),nums.end());
        int divisor=-1;

        while(st<=end){
            int mid=st+(end-st)/2;
            int total=cal(nums,mid);
            if(total<=threshold){
                divisor=mid;
                end=mid-1;
            }
            else 
                st=mid+1;
        }
        return divisor;     
    }
int main(){
    vector<int>nums={1,2,5,9};
    int threshold=6;

    cout<<"Smallest divisor: "<<smallestDivisor(nums,threshold)<<endl;

    return 0;
}