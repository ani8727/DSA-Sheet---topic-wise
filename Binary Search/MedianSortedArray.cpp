#include <iostream>
#include <vector>
using namespace std;

// 4. Median of Two Sorted Arrays

//Brute force appraoch 
// double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size();
//         int n = nums2.size();
//         vector<int> nums(m+n);
//         int i = 0, j = 0, k = 0;
        
//         // Merge the arrays
//         while(i < m && j < n) {
//             if(nums1[i] < nums2[j]){
//                 nums[k++] = nums1[i++];
//             } else {
//                 nums[k++] = nums2[j++];
//             }
//         }
        
//         while(i < m){ 
//             nums[k++] = nums1[i++];
//         }
//         while(j < n){
//             nums[k++] = nums2[j++];
//         }
        
//         int p = m + n;
//         if (p % 2 == 0)
//             return (nums[p/2 - 1] + nums[p/2]) / 2.0;
//         else
//             return nums[p/2];
// }

// better appraoch
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m=nums1.size();
    int n=nums2.size();
    int p=m+n;

    int idx2=p/2;  // agar 10 elemet hue to 4,5 idx my answer idx2=10/2->5
    int idx1=idx2-1; // idx 4-> 5-1
    // store both element
    int idxEle1=-1;
    int idxEle2=-1;
    // add a bool to check find
    bool find=false;

    int i=0;
    int j=0;
    int cnt=0; // its count to no. element passes so when goes to that index its took element

    // Merge-like traversal until both median elements are found
    while(i<m && j<n){
        if(nums1[i]<nums2[j]){
            // kya us idex pe pahuch gye idx1 and idx2
            if(cnt==idx1) idxEle1=nums1[i]; 
            if(cnt==idx2) idxEle2=nums1[i]; 
            i++;  // 1st index mil  gya increase kar diya
            cnt++; // ek mil gya sorted form mai
        } else { 
            // kya us idex pe pahuch gye idx1 and idx2
            if(cnt==idx1) idxEle1=nums2[j]; 
            if(cnt==idx2) idxEle2=nums2[j]; 
            j++;  // 1st index mil  gya increase kar diya
            cnt++; // ek mil gya sorted form mai
        }
        // if both find then exit loop
        if(idxEle1>-1 && idxEle2>-1){
            find=true;
            break;
        }
    }
    // add if remaing some element
    while(!find && i<m){
        // kya us idex pe pahuch gye idx1 and idx2
        if(cnt==idx1) idxEle1=nums1[i]; 
        if(cnt==idx2) idxEle2=nums1[i]; 
        i++; // 1st index mil  gya increase kar diya
        cnt++; // ek mil gya sorted form mai
    }
    while(!find && j<n){
        // kya us idex pe pahuch gye idx1 and idx2
        if(cnt==idx1) idxEle1=nums2[j]; 
        if(cnt==idx2) idxEle2=nums2[j]; 
        j++; // 1st index mil  gya increase kar diya
        cnt++; // ek mil gya sorted form mai
    }
    // if Even- retrun averge for both n/2 , n/2-1 
    if(p%2==0){
        return (double)(idxEle1+idxEle2)/2;
    }else{ // odd - return n/2
        return idxEle2;
    }
}

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    double median = findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << median << endl;

    vector<int> test1 = {1, 2};
    vector<int> test2 = {3, 4};
    cout << "median: " << findMedianSortedArrays(test1, test2) << endl;
    
    return 0;
}