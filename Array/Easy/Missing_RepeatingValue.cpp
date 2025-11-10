//  2965. Find Missing and Repeated Values

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;


// 1. brute force approach using map
pair<int, int> find(vector<vector<int>> grid){
   pair<int,int> ans;
   unordered_map<int,int> mp;
   int sum=0;
   int repeate;
   int missing;
   int size=0;

   for(vector<int> num: grid){
    for(int i: num){
        mp[i]++;   // freq count
        sum+=i;   // total sum
        size++;   // size
    }
   }
   for(auto p: mp){
    if(p.second>1){  // repeate find 
        repeate=p.first;
    }
   }
   int actualSum=sum-repeate;   // actaul sum without repeate
   int calSum=0;

   for(int i=1;i<=size;i++){
    calSum+=i;               // cal sum for all if not repeated present
   }
  
   missing=calSum-actualSum;   // missing value that became needed sum

   ans={repeate,missing};

   return ans;
}

// 2. using set  - grid must be square

vector<int> mising(vector<vector<int>> grid){
    int n=grid.size();  // (1,n2)

    unordered_set<int> s;

    int repeate=-1, missing=-1;

    int actualSum=0, expSum=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            actualSum+=grid[i][j];
            if(s.find(grid[i][j]) != s.end()){
              repeate=grid[i][j];
            }
            s.insert(grid[i][j]);
        }
    }

    expSum = ((n*n)*(n*n + 1))/2;

    missing = expSum + repeate - actualSum;

    return {repeate,missing};
}

int main(){
    vector<vector<int>> grid={{1,2,5},{3,4,7},{6,6,9}};
   
    pair<int,int> ans=find(grid);

    cout<<ans.first<<" "<<ans.second<<endl;

    vector<int> ans2=mising(grid);

    cout<<ans2[0]<<" "<<ans2[1]<<endl;

    return 0;

}
