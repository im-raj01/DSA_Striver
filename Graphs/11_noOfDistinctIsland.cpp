#include<bits/stdc++.h>
using namespace std;
#define ll long long
// gfg -> https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

  void dfs(int row, int col,vector<vector<int>>& vis,vector<vector<int>>& grid,int row0,int col0,
        vector<pair<int,int>>& v)
  {
       int n = grid.size();
        int m = grid[0].size();
      vis[row][col] = 1;
      int delRow[] = {-1,0,1,0};
      int delCol[] = {0,1,0,-1};
      v.push_back({(row-row0),(col-col0)});
      
      for(int i = 0;i<4;i++){
          int nrow = row + delRow[i];
          int ncol = col + delCol[i];
          if(nrow >= 0 && nrow<n && ncol >=0 && ncol <m 
            && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                dfs(nrow,ncol,vis,grid,row0,col0,v);
            }
          
      }
  }

    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        set<vector<pair<int,int>>>st;
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    vector<pair<int,int>>v;//vector of pair of coordinates considering base;
                    dfs(i,j,vis,grid,i,j,v);
                    st.insert(v);
                }
            }
        }
        return st.size();
    }

int main()
{

 return 0;
}