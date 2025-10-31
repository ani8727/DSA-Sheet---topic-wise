// Finding Sqrt of a number using Binary Search

#include<iostream>
using namespace std;

// brute force approach -n/2
// int sqrt(int n){
//     int ans=0;
//     for(int i=1;i*i<=n;i++){
//         cout<<i<<endl;
//         if(i*i<=n) ans=i;
//     }
//     return ans;
// }

// optimal -log n

int sqrt(int n){
    if (n == 0 || n == 1) return n;
    int st=1, end=n/2, ans=1;
    while(st<=end){
        int mid=st+(end-st)/2;
        cout<<mid<<endl;
        if(mid*mid>n) end=mid-1;
        else{ 
            ans=mid;
            st=mid+1;
        }
    }
    return ans;
}
int main(){
    int n=125;
    cout<<"Sqrt: "<<sqrt(n)<<endl;
    return 0;
}