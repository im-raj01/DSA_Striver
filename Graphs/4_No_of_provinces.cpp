#include<bits/stdc++.h>
using namespace std;
#define ll long long

//547-> https://leetcode.com/problems/number-of-provinces/description/
class Solution {
public:
    void dfs(vector<int>adj[],vector<int>& vis,int node){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(adj,vis,it);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adj[n+1];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j] == 1){
                    adj[i+1].push_back(j+1);

                }
            }
        }

        int cnt = 0;
        int start = 1;
        vector<int>vis(n+1,0);
        for(int i = 1;i<=n;i++){
            if(!vis[i]){
                cnt++;
                dfs(adj,vis,i);
            }
        }
        return cnt;
    }
};

int main()
{

 return 0;
}