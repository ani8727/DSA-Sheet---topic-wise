#include<iostream>
#include<vector>

using namespace std;

// Returns the (row, col) of target if found, otherwise (-1, -1)
pair<int, int> search(const vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    if (n == 0) return {-1, -1};
    int m = matrix[0].size();
    int row = 0, col = m - 1;
    while (row < n && col >= 0) {
        if (matrix[row][col] == target)
            return {row, col};
        else if (matrix[row][col] > target)
            col--;
        else
            row++;
    }
    return {-1, -1};
}

int main(){
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    pair<int, int> p = search(matrix, 20);
    cout << p.first << " " << p.second << endl;
    return 0;
}