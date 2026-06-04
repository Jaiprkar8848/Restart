#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

bool issafe(int row,int col,int val,vector<vector<int>> &board){
    int n=board.size();
    for(int j=0;j<n;j++){
        if(board[row][j]==val) return false;
    }
    for(int i=0;i<n;i++){
        if(board[i][col]==val) return false;
    }
    // smaller box
    // offset means starting se uski distance maanlo kind of
    // (2,0) to (3,1) -> if(2,0) start of box and size 2x2 
    // offset either 0 or 1
    // 3 -> 2+offset -> 2(rowStart)
    // 1 -> 0+offset -> 0(colStart)
    // rowStart=3-offset 
    // colStart=1-offset
    // offset=val%2
    int N=sqrt(n);
    int rowStart=row-row%N;
    int colStart=col-col%N;
    int rowEnd=rowStart+N-1;
    int colEnd=colStart+N-1;
    for(int i=rowStart;i<=rowEnd;i++){
        for(int j=colStart;j<=colEnd;j++){
            if(board[i][j]==val) return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>> &board){
    int n=board.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==0){
                for(int val=1;val<=n;val++){
                    if(issafe(i,j,val,board)){
                        board[i][j]=val;
                        bool ans_remaining_ka=solve(board);
                        if(ans_remaining_ka) return true;
                        // means humne jo rkha vo shi nhi tha
                        board[i][j]=0;
                    }
                }
                // if all possibilities checked and we not got the answer
                return false;
            }
        }
    }
    // kahi bhi false nhi mila means hamara answer shi h
    return true;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> board(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
    bool ans=solve(board);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}