#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //jo bhi rotten oranges hain usko store kar lo
        int vis[n][m];
        queue<pair<pair<int,int>,int>>q; // <{row,col},time>

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }

        int time = 0;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tm = q.front().second;
            time = max(tm,time);

            q.pop();

            for(int i = 0;i<4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(nRow>=0 && nRow < n && nCol>=0 && nCol<m 
                   && grid[nRow][nCol] == 1 && vis[nRow][nCol] !=2){
                        vis[nRow][nCol] = 2;
                        q.push({{nRow,nCol},tm+1});
                    }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1 && vis[i][j] != 2){
                    return -1;
                }
            }
        }
        return time;


    }
};
int main()
{

 return 0;
}