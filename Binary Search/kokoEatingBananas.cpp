// 875. Koko Eating Bananas
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>

using namespace std;

int time(vector<int>& piles, int H){
    int totalH=0;
    for(int i=0;i<piles.size();i++){
      totalH+=ceil((double)piles[i]/H);
    }
    return totalH;
}
/*
int Eating(vector<int>& piles, int hour){
    int n=*max_element(piles.begin(),piles.end());
    for(int i=1;i<=n;i++){
        int timetaken=time(piles,i);
        if(timetaken<=hour){
            return i;
        }
    }
}
*/
int Eating(vector<int>& piles,int hour){
    int st=1, end=*max_element(piles.begin(),piles.end()), timetaken=0, ans=INT_MAX;
    while(st<=end){
        int mid=st+(end-st)/2;
        timetaken=time(piles,mid);
        if(timetaken<=hour){
            end=mid-1;
            ans=min(ans,mid);
        }else{
            st=mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> piles={3,6,7,11};
    cout<<"No. of Bananas per hour: "<<Eating(piles,8)<<endl;
    return 0;
}