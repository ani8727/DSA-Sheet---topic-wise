// 1539. Kth Missing Positive Number

#include<iostream>
#include<vector>
using namespace std;

bool isPresent(vector<int>arr, int i){
    for(int ele:arr){
        if(ele==i) return true;
    }
    return false;
}

 int findKthPositive(vector<int>& arr, int k) {
    int st=1;
    int missing=0;
    int kth=-1;
    while(missing<k){
        cout<<st<<" ";
        if(!isPresent(arr, st)){
            missing++;
            kth=st;
            cout<<missing<<kth<<" ";
        }
        st++;
    }
    return kth;
}

int main(){
    vector<int> nums={2,3,4,7,11};
    int k=5;
    cout<<"kth Misisng Number: "<<findKthPositive(nums, k);

    return 0;
}