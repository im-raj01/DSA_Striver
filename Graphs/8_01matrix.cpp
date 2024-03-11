
#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // take vis and a distance matrix to store ans:
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>distance(m,vector<int>(n));

        //queue to perform bfs:
        queue<pair<pair<int,int>,int>>q;// to store coordinates and minm steps
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }

        //
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;

            q.pop();
            distance[row][col] = steps;

            for(int i = 0;i<4;i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow >= 0 && nrow <m && ncol >=0 && ncol<n 
                    && vis[nrow][ncol] == 0){
                        q.push({{nrow,ncol},steps+1});
                        vis[nrow][ncol] = 1;
                }
            }
        }
        return distance;
    }
};

int main()
{

 return 0;
}