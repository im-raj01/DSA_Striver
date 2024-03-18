#include<bits/stdc++.h>
using namespace std;
#define ll long long


// LINK: https://www.geeksforgeeks.org/problems/eventual-safe-states/1
// USING DFS:
// User function Template for C++

class Solution {
  private:
  bool dfs(int node,int vis[],int pathVis[],vector<int> adj[],int count[]){
      vis[node] = 1;
      pathVis[node] = 1;
      
      // check for cycle:
      for(auto it:adj[node]){
          if(!vis[it]){
              if(dfs(it,vis,pathVis,adj,count)==true)return true;
          }
          else if(pathVis[it] == 1){
              return true;
          }
      }
      
      count[node] =1;
      pathVis[node] = 0;
      return false;
      
  }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int vis[V] = {0};
        int pathVis[V] = {0};
        
        int count[V] = {0};
        vector<int>ans;
        
        for(int i = 0;i<V;i++){
            if(!vis[i])
            dfs(i,vis,pathVis,adj,count);
        }
        
        for(int i = 0;i<V;i++){
            if(count[i] == 1)ans.push_back(i);
        }
        
        return ans;
        
        
    }
};

//USING BFS OR TOPO SORT:
class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int>adjRev[V];
        int inDegree[V]={0};
        
        for(int i = 0;i<V;i++){
            // node is i->it 
            for(auto it:adj[i]){
                adjRev[it].push_back(i);
            }
        }
        
        for(int i = 0;i<V;i++){
            for(auto it:adjRev[i]){
                inDegree[it]++;
            }
        }
        
        queue<int>q;
        for(int i= 0;i<V;i++){
            if(inDegree[i] == 0)q.push(i);
        }
        
        vector<int>safeNodes;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            
            for(auto it:adjRev[node]){
                inDegree[it]--;
                if(inDegree[it] == 0)q.push(it);
            }
            
        }
        
        
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
        
    }
};

int main()
{

 return 0;
}