// 54. Spiral Matrix

#include<iostream>
#include<vector>
using namespace std;

vector<int> spinalMatrix(vector<vector<int>>matrix){
    int m=matrix.size();  // rows
    int n=matrix[0].size(); // columns
    int e=m*n; // elements

    vector<int> spinal;

    int top=0;  // 1st row
    int bottom=m-1;  // last row
    int left=0;    // first col
    int right=n-1;  // last col
    int count=0;   // element count

    while(top <= bottom && left <= right){
        // left -> right
        for(int i=left;i<=right;i++){
            spinal.push_back(matrix[top][i]);
            count++;
            cout<<matrix[top][i]<<" "<<count<<endl;
        }
        top++;
        // top -> bottom
        for(int i=top;i<=bottom;i++){
            spinal.push_back(matrix[i][right]);
            count++;
            cout<<matrix[i][right]<<" "<<count<<endl;
        }
        right--;
        if(top<=bottom){
            // right -> left
            for(int i=right;i>=left;i--){
                spinal.push_back(matrix[bottom][i]);
                count++;
                cout<<matrix[bottom][i]<<" "<<count<<endl;
            }
            bottom--;
        }
        if(left<=right) {
            // bottom -> top
            for(int i=bottom;i>=top;i--){
                spinal.push_back(matrix[i][left]);
                count++;
                cout<<matrix[i][left]<<" "<<count<<endl;
            }
            left++; 
        }
    }
    return spinal;
}

int main(){
    vector<vector<int>> matrix={{1,2,3,4,5},{16,17,18,19,6},{15,24,25,20,7},{14,23,22,21,8},{13,12,11,10,9}};

    vector<int>spinal=spinalMatrix(matrix);

    for(int i: spinal){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}