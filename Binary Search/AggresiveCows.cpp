//  You are given an array 'arr' of size 'n' which denotes the position of stalls.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cowPlaced(vector<int> stalls, int cows, int dist){
    int countCow=1;
    int last=stalls[0];
    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-last>=dist){
            countCow++;
            last=stalls[i];
        }
        if(countCow>=cows) return true;
    }
    return false;
}

int maxDist(vector<int> stalls, int k){
    sort(stalls.begin(),stalls.end());

    int end=stalls[stalls.size()-1]-stalls[0];

    for(int st=1;st<=end;st++){
        if(cowPlaced(stalls,k,st)){
            continue;
        }else{
            return st-1;
        }
    }
    return end;
}

int main(){
    vector<int> stalls={0,3,4,7,10,9};
    int k=4;

    cout<<"Max of Min Distance: "<<maxDist(stalls, k);

    return 0;
}