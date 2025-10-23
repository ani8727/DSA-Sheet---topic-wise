#include<iostream>
#include<vector>
using namespace std;

// The Maximum Points You Can Obtain from Cards problem (LeetCode 1423) allows you to pick exactly k cards from the start or the end, not from the middle.

// int maxScore(vector<int>& cardPoints,int k){
//     int lSum=0;
//     int rSum=0;
//     int maxSum=0;
//     for(int i=0;i<k;i++){
//         lSum+=cardPoints[i];
//     }
//     maxSum=lSum;
//     int rIdx=cardPoints.size()-1;
//     for(int i=k-1;i>=0;i--){
//         lSum-=cardPoints[i];
//         rSum+=cardPoints[rIdx];
//         rIdx--;
//         maxSum=max(maxSum,rSum+lSum);
//     }
//     return maxSum;
// }

// “Find the maximum sum of any contiguous subarray of length k.”

int maxScore(vector<int>& cardPoints,int k){
    int n=cardPoints.size();
    int maxPoints=0, windowPoints=0;
    for(int i=0;i<k;i++){
        windowPoints+=cardPoints[i];
    }
    maxPoints=windowPoints;
    for(int i=k;i<n;i++){
        windowPoints-=cardPoints[i-k];
        windowPoints+=cardPoints[i];
        maxPoints=max(maxPoints,windowPoints);
    }
    return maxPoints;
}

int main(){
    vector<int> cardPoints={1,2,3,4,5,6,1};
    cout<<"Maximum point: "<<maxScore(cardPoints,3);
    return 0;
}

