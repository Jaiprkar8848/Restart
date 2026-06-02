#include<iostream>
#include<vector>
using namespace std;

bool isSafe_row(int row,int col,int n,vector<vector<int>> &board){
    // lower possibilites becz hum row wise bhar rhe toh aage ki row main queen h hi nhi
    // same row main koi queen nhi hogi 2 possibilites aur cut
    // remaining -> up,left upper,right upper
    int r=row;
    int c=col;
    // left upper
    while(row>=0 && col>=0){
        if(board[row][col]==1)
            return false;
        row--,col--;
    }
    row=r;
    col=c;
    // upper
    while(row>=0){
        if(board[row][col]==1)
            return false;
        row--;
    }
    row=r;
    col=c;
    // right upper
    while(col<n && row>=0){
        if(board[row][col]==1)
            return false;
        col++;
        row--;
    }
    return true;
}

void nqueens_row(int row,int n,vector<vector<int>> &board){
    if(row==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    for(int col=0;col<n;col++){
        if(isSafe_row(row,col,n,board)){
            board[row][col]=1;
            nqueens_row(row+1,n,board);
            board[row][col]=0;   // backtrack
        }
    }
}

bool isSafe_col(int row,int col,int n,vector<vector<int>> &board){
    // 3 right possibilites are out becz col wise fill kr rhe toh aage ke col main kuch h nhi
    // same col main queen nhi hogi toh 2 possibilite aur cut
    // remaining -> left upper, left lower, same row
    int r=row;
    int c=col;

    // left upper
    while(row>=0 && col>=0){
        if(board[row][col]==1)
            return false;
        row--,col--;
    }
    row=r;
    col=c;
    // same row
    while(col>=0){
        if(board[row][col]==1)
            return false;
        col--;
    }
    row=r;
    col=c;
    // left lower
    while(row<n && col>=0){
        if(board[row][col]==1)
            return false;
        row++,col--;
    }
    return true;
}

void nqueens_col(int col,int n,vector<vector<int>> &board){
    if(col==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe_col(row,col,n,board)){
            board[row][col]=1;
            nqueens_col(col+1,n,board);
            board[row][col]=0;  // backtrack
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> board1(n,vector<int>(n,0));
    nqueens_row(0,n,board1);

    cout<<endl;

    vector<vector<int>> board2(n,vector<int>(n,0));
    nqueens_col(0,n,board2);
    return 0;
}