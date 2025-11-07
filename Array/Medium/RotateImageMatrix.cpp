// 48. Rotate Image

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// brute force approach - using matrix space;
// vector<vector<int>> rotation(vector<vector<int>> matrix){
//     int n=matrix.size(); // n*n -> matrix row=col
//     vector<vector<int>> rotate(n,vector<int>(n));

//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             rotate[j][n-1-i]=matrix[i][j];
//         }
//     }
//     return rotate;
// }

vector<vector<int>> rotation(vector<vector<int>> matrix){
    int n=matrix.size(); // n*n -> matrix row=col
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
           swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());    
    }
    return matrix;
}

int main(){
    vector<vector<int>>matrix{{3,6,9},{2,5,8},{1,4,7}};

    vector<vector<int>> rotate=rotation(matrix);

    for(vector<int> row: rotate){
        for(int ele: row){
            cout<<ele<<" ";
        }cout<<endl;
    }cout<<endl;
    return 0;
} 