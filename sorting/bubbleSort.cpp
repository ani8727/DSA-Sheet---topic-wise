#include<iostream>
#include<vector>
using namespace std;

void sort(vector<int> &num){
    int count=0;
    int swap=0;
    for(int i=0;i<num.size()-1;i++){
        bool isswap=false;
        for(int j=0;j<num.size()-i-1;j++){
            count++;
            if(num[j]>num[j+1]){
                int temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
                swap++;
                isswap=true;
            }
        }
        if(!isswap) break;
    }
    cout<<swap<<" "<<count<<endl;
}
int main(){
    vector<int> num={1,2,3,4,5};
    
    sort(num);
    for(int i=0;i<num.size();i++){
        cout<<num[i]<<" ";
    }
    return 0;
}