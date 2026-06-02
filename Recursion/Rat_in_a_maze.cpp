#include<iostream>
#include<vector>
using namespace std;

void rats(int r,int c,int n,vector<vector<int>> &maze,vector<vector<int>> &vis,string &curr){
    if(r==n-1 && c==n-1){
        cout<<curr<<endl;
        return;
    }
    vis[r][c]=1;
    // down
    if(r+1<n && maze[r+1][c]==1 && vis[r+1][c]==0){
        curr+='D';
        rats(r+1,c,n,maze,vis,curr);
        curr.pop_back();
    }
    // left
    if(c-1>=0 && maze[r][c-1]==1 && vis[r][c-1]==0){
        curr+='L';
        rats(r,c-1,n,maze,vis,curr);
        curr.pop_back();
    }
    // right
    if(c+1<n && maze[r][c+1]==1 && vis[r][c+1]==0){
        curr+='R';
        rats(r,c+1,n,maze,vis,curr);
        curr.pop_back();
    }
    // up
    if(r-1>=0 && maze[r-1][c]==1 && vis[r-1][c]==0){
        curr+='U';
        rats(r-1,c,n,maze,vis,curr);
        curr.pop_back();
    }
    vis[r][c]=0;
    return;
}
void printWays(vector<vector<int>> &maze){
    string curr;
    int n=maze.size();
    vector<vector<int>> vis(n,vector<int>(n,0));
    rats(0,0,n,maze,vis,curr);
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> maze(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
        }
    }
    printWays(maze);
}