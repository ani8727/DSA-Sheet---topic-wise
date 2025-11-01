// 1011. Capacity To Ship Packages Within D Days

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int reqDays(vector<int>& weights, int cap){
        int days=1;
        int load=0;
        for(int weight:weights){
            if(load+weight>cap){
                days++;
                load=weight;
            }else{
                load+=weight;
            }
        }
        return days;
}
// brute force
// int shipWithinDays(vector<int>& weights, int days) {
//     int mini=*max_element(weights.begin(),weights.end());
//      int maxi=0;
//     for(int weight:weights){
//         maxi+=weight;
//     }
//     for(int i=mini;i<=maxi;i++){
//         int totalDays=reqDays(weights,i);
//         if(totalDays<=days){
//             return i;
//         }
//     }
//     return -1; 
// }

// better appraoch
int shipWithinDays(vector<int>& weights, int days) {
    int mini=*max_element(weights.begin(),weights.end());
    int maxi=0;
    for(int weight:weights){
        maxi+=weight;
    }
    while(mini<maxi){
        int mid=mini+(maxi-mini)/2;
        int totalDays=reqDays(weights,mid);
        if(totalDays>days){
            mini=mid+1;
        }else{
            maxi=mid;
        }
    }
    return mini; 
}

int main(){
    vector<int> weights={1,2,3,4,5,6,7,8,9,10};
    int days=5;

    cout<<"Capacity: "<<shipWithinDays(weights,days);

    return 0;

    }