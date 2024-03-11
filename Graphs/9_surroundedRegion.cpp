#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
private:
void dfs(vector<vector<int>> &vis,vector<vector<char>>& board,int row, int col,
         int delRow[],int delCol[]){
             int m = board.size();
             int n = board[0].size();
             vis[row][col] = 1;
             for(int i = 0;i<4;i++){
                 int nrow = row + delRow[i];
                 int ncol = col + delCol[i];

                 if(nrow >= 0 && nrow<m && ncol>=0 && ncol <n 
                   && board[nrow][ncol] == 'O' && vis[nrow][ncol] == 0){
                       dfs(vis,board,nrow,ncol,delRow,delCol);
                   }
             }
         }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        // traverse 1st and last row:
        for(int j=0;j<n;j++){
            if(board[0][j] == 'O'){
                dfs(vis,board,0,j,delRow,delCol);
            }
            if(board[m-1][j] == 'O'){
                dfs(vis,board,m-1,j,delRow,delCol);
            }
        }

        // 1st and last row me O check karenge:
        for(int i = 0;i<m;i++){
            if(board[i][0] == 'O'){
                dfs(vis,board,i,0,delRow,delCol);
            }
            if(board[i][n-1] == 'O'){
                dfs(vis,board,i,n-1,delRow,delCol);
            }
        }

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(vis[i][j] == 0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        return;

    }
};

int main()
{

 return 0;
}