#include<bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(vector<vector<int>>& image,vector<vector<int>> &ans ,int startingColor,int sr,int sc,int color){
        int n = image.size();
        int m = image[0].size();

        ans[sr][sc] = color;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        for(int i = 0;i<4;i++){
            int nsr = sr+delRow[i];
            int nsc = sc + delCol[i];

            if(nsr >= 0 && nsr <n && nsc>=0 && nsc < m 
              && image[nsr][nsc] == startingColor && ans[nsr][nsc] != color){
                dfs(image,ans,startingColor,nsr,nsc,color);
              }
        }

    }
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startingColor = image[sr][sc];
        vector<vector<int>>ans = image;
        dfs(image,ans,startingColor,sr,sc,color);
        return ans;

    }

int main()
{
    int n = 3;
    int m = 3;
    vector<vector<int>>image
    {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    vector<vector<int>>ans = floodFill(image,1,1,2);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
        
    }
    




 return 0;
}