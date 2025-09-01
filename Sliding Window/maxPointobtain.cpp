#include<iostream>
#include<vector>
using namespace std;

int maxScore(vector<int>& cardPoints,int k){
    int lSum=0;
    int rSum=0;
    int maxSum=0;
    for(int i=0;i<k;i++){
        lSum+=cardPoints[i];
    }
    maxSum=lSum;
    int rIdx=cardPoints.size()-1;
    for(int i=k-1;i>=0;i--){
        lSum-=cardPoints[i];
        rSum+=cardPoints[rIdx];
        rIdx--;
        maxSum=max(maxSum,rSum+lSum);
    }
    return maxSum;
}
int main(){
    vector<int> cardPoints={1,2,3,4,5,6,1};
    cout<<"Maximum point: "<<maxScore(cardPoints,3);
    return 0;
}
