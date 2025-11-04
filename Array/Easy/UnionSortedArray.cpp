// Union of Two Sorted Arrays

// The union of two arrays can be defined as the common and distinct elements in the two arrays.NOTE: Elements in the union should be in ascending order.

#include<iostream>
#include<vector>
#include<set>
using namespace std;

// brute force approach
// vector<int> findUnion(vector<int>nums1, vector<int> nums2){
//     int m=nums1.size();
//     int n=nums2.size();

//     vector<int>nums;
//     set<int> st;

//     for(int num: nums1) st.insert(num);
//     for(int num: nums2) st.insert(num);

//     for(int s: st){
//         nums.push_back(s);
//     }

//     return nums;
// }

// better approach
vector<int> findUnion(vector<int>nums1, vector<int> nums2){
    int m=nums1.size();
    int n=nums2.size();

    vector<int>nums;
    int i=0;
    int j=0;
    int k=0;

    while(i<m && j<n){
        if(nums1[i]<nums2[j]){
            if(nums.empty() || nums.back()!=nums1[i]){
                nums.push_back(nums1[i]);
            }
            i++;
        }
        else if(nums2[j]<nums1[i]){
            if(nums.empty() || nums.back()!=nums2[j]){
                nums.push_back(nums2[j]);
            }
            j++;
        }
        else{
            if(nums.empty() || nums.back()!=nums1[i]){
                nums.push_back(nums1[i]);
            }
            i++;
            j++;
        }
    }
    
    while(i<m){
        if(nums.empty() || nums.back()!=nums1[i]){
            nums.push_back(nums1[i]);
        }
        i++;
    }
    
    while(j<n){
        if(nums.empty() || nums.back()!=nums2[j]){
            nums.push_back(nums2[j]);
        }
        j++;
    }
    
    return nums;
}

int main(){
    vector<int> nums1={1,2,3,4,5,6,7,8,9,10};
    vector<int> nums2={2,3,4,4,5,11,12};

    vector<int>unions=findUnion(nums1,nums2);

    for(int ele: unions){
        cout<<ele<<" ";
    }cout<<endl;

    return 0;
}