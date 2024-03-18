#include<bits/stdc++.h>
using namespace std;
#define ll long long

// link -> https://leetcode.com/problems/number-of-enclaves/
class Solution {
    private:
    // a dfs function to visit all ones which is connected to the boundary:
    void dfs(vector<vector<int>>& vis,vector<vector<int>>& grid,int row,int col,
            int delRow[],int delCol[]){
                int m = grid.size();
                int n = grid[0].size();
                vis[row][col] = 1;
            for(int i = 0;i<4;i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow >= 0 && nrow<m && ncol>=0 && ncol <n
                 && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                     vis[nrow][ncol] = 1;
                     dfs(vis,grid,nrow,ncol,delRow,delCol);
                 }
            }

        }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //visited vector:
        vector<vector<int>>vis(m,vector<int>(n,0));
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        //traversing the boundary :
        for(int i = 0;i<m;i++){
            for(int j= 0;j<n;j++){
                if(i == 0 || i == m-1 || j==0 || j==n-1){
                    if(grid[i][j] == 1){
                        dfs(vis,grid,i,j,delRow,delCol);
                    }
                }
            }
        }
        int cnt = 0;
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                if(vis[i][j] == 0 && grid[i][j] == 1)cnt++;
            }
        }
        return cnt;
        
    }
};

int main()
{

 return 0;
}