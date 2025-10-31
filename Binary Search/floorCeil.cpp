// Floor/Ceil in Sorted Array

#include<iostream>
#include<vector>
using namespace std;

pair<int, int>floorCeil(vector<int> nums, int x){
    int st=0, end=nums.size()-1;
    int floor=-1, ceil=-1;

    while(st<=end){
        int mid=st+(end-st)/2;
        if(nums[mid]==x) return {nums[mid],nums[mid]};
        else if(nums[mid]>x){
            ceil=nums[mid];
            end=mid-1;
        }
        else{
            floor=nums[mid];
            st=mid+1;
        }
    }
    return {floor,ceil};
}

int main(){
    vector<int> nums={3, 4, 7, 8, 8, 10};

    pair<int,int> ans=floorCeil(nums,6);

    cout<<"floor(equal or less): "<<ans.first<<endl<<"Ceil(equla or greater): "<<ans.second<<endl;

    return 0;
}