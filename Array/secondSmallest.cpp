#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main(){
    vector<int> nums={2,4,6,1,3,9,0};

    int smallest=INT_MAX;
    int sSmallest =INT_MAX;

    for(int &num: nums){
       if(num<smallest){
        sSmallest=smallest;
        smallest=num;
       }else if(num>smallest && num<sSmallest){
        sSmallest=num;
       }
    }
    cout<<sSmallest;
}
