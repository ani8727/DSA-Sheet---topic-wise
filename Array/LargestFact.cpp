#include<iostream>
#include<vector>
using namespace std;

// this code for small number
int factorial(int num){
    if(num<0){
        return 0;
    }
    int fact=1;
    while(num>0){
        fact*=num;
        num--;
    }
    return fact;
}

// for large number cal. factorial
void multiply(vector<int>& arr, int& size, int multiplier){
    int carry = 0;
    for(int i=0; i<size;i++){
        int res=multiplier*arr[i];

        res = res+carry;

        arr[i] = res%10;

        carry = res/10;
    }
    // carry
   while(carry>0){
    arr[size]=carry%10;
    size++;
    carry= carry/10;
   }
}
vector<int> fact_largest(int num){
    vector<int>arr(10000,0);
    arr[0]=1;
    int size = 1;

    for(int multiplier=2;multiplier<=num;multiplier++){
        multiply(arr,size,multiplier);
    }
    vector<int> ans;
    for(int i=size-1; i>=0; i--){
        ans.push_back(arr[i]);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int fact=factorial(n);
    cout<<fact<<endl;
    vector<int> fact2=fact_largest(n);
    for(int &i:fact2){
        cout<<i;
    }
    return 0;
}