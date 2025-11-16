// Rat in Maze

#include<iostream>
#include<vector>
using namespace std;

vector<string> result;

bool isSafe(int i,int j, int n){
    return(i>=0 && i<n && j>=0 && j<n);
}

void solve(int i, int j, vector<vector<int>>& maze, int n, string& path){
    if(!isSafe(i,j,n) || maze[i][j]==0){
        return;
    }
    if(i==n-1 && j==n-1){
        result.push_back(path);
        return;
    }
    maze[i][j]=0;

    path.push_back('D');
    solve(i+1,j,maze,n,path);
    path.pop_back();

    path.push_back('R');
    solve(i,j+1,maze,n,path);
    path.pop_back();

    path.push_back('U');
    solve(i-1,j,maze,n,path);
    path.pop_back();

    path.push_back('L');
    solve(i,j-1,maze,n,path);
    path.pop_back();

    maze[i][j]=1;
}

vector<string> findPath(vector<vector<int>>& maze){
    string path="";

    int n=maze.size();

    solve(0,0,maze,n,path);

    return result;

}

int main(){
    vector<vector<int>> maze={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};

    vector<string> ans=findPath(maze);

    for(string st: ans){
        cout<<st<<endl;
    }
    return 0;
}