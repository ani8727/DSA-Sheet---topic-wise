// Allocate Minimum Pages

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int pageAllocate(vector<int>arr, int pages){
    int totalPages=0;
    int student=1;
    for(int page=0;page<arr.size();page++){
        if(totalPages+arr[page]<=pages){
            totalPages+=arr[page];
        }else{
            student++;
            totalPages=arr[page];  
        }
    }
    return student;
}
// brute force approach
// int findPages(vector<int> &arr, int k) {  
//     if(k>arr.size()) return -1;
//     int st=*max_element(arr.begin(),arr.end());
//     int end=accumulate(arr.begin(), arr.end(), 0);
//     cout<<st<<" "<<end<<endl;
//     for(int i=st;i<=end;i++){
//         int allocate=pageAllocate(arr,i);
//         cout<<i<<" "<<allocate<<endl;
//         if(allocate==k){
//             cout<<allocate<<endl;
//              return i;
//         }
//     }
//     return -1;
// }

//optimal approach
int findPages(vector<int> &arr, int k) {
        
    if(k>arr.size()) return -1;
    int st=*max_element(arr.begin(),arr.end());
    int end=accumulate(arr.begin(), arr.end(), 0);

    while(st<=end){
        int mid=st+(end-st)/2;
        int allocate=pageAllocate(arr,mid);
        if(allocate>k) st=mid+1;
        else end=mid-1;
    }
    return st;
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int k = 4;
    int ans = findPages(arr, k);
    cout <<ans<<endl;
    return 0;
}