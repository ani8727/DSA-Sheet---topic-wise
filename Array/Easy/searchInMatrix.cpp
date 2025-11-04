// 74. Search a 2D Matrix

#include<iostream>
#include<vector>
using namespace std;

// brute force appraoch
// bool search(vector<vector<int>> matrix, int k){
//     for(vector<int> row: matrix){
//         for(int num: row){
//             cout<<num<<" ";
//             if(num==k) return true;
//         }
//     }
//     return false;
// }

// better approach- sorted array
// bool binary(vector<int>nums, int k){
//     int n=nums.size();
//     int st=0, end=n-1;
//     while(st<=end){
//         int mid=st+(end-st)/2;
//         if(nums[mid]==k) return true;
//         else if(nums[mid]<k) st=mid+1;
//         else end=mid-1;
//     }
//     return false;
// }

// bool search(vector<vector<int>> matrix, int k){
//     for(vector<int> row: matrix){
//         bool flag=binary(row,k);
//         if(flag) return true;
//     }
//     return false;
// }

// Optimal Approach - full matrix sorted
bool search(vector<vector<int>> nums, int k){
    int n=nums.size(); // row count
    int m=nums[0].size();  // column count
    int st=0, end=n*m-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        int val=nums[mid/m][mid%m]; // make mid to 2D form 
        if(val==k) return true;
        else if(val<k) st=mid+1;
        else end=mid-1;
    }
    return false;
}

int main(){
    vector<vector<int>> matrix ={{1,3,5,7},{10,11,16,20},{23,30,34,60}};

    int k=34;

    if(search(matrix,k)) cout<<"Found";
    else cout<<"Not Found";

    return 0;
}