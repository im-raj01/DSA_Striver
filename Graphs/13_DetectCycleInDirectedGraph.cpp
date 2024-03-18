#include<bits/stdc++.h>
using namespace std;
#define ll long long


// problem link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// using DFS:
class Solution {
  private:
  
  bool dfsCheck(int node,vector<int>adj[],int vis[],int pathVis[]){
      vis[node] = 1;
      pathVis[node] = 1;
      
      for(auto it:adj[node]){
          if(!vis[it]){
              if(dfsCheck(it,adj,vis,pathVis))return true;
          }
          else if(pathVis[it]){
              return true;
          }
      }
      
      //backtrack:
      pathVis[node] = 0; 
      return false;
  }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here.
        int vis[V]={0};
        int pathVis[V] = {0};
        
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                if(dfsCheck(i,adj,vis,pathVis))return true;
            }
        }
        return false;
        
    }
};

// USInG BFS  or kahn's algorithm:
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        // Using Toposort or kahn's algorithm:
    int inDegree[V] = {0}; // to store the indegree of all nodes:
	   for(int i = 0;i<V;i++){
	       for(auto it:adj[i]){
	           inDegree[it]++;
	       }
	   }
	   
	   queue<int>q;
	   for(int i = 0;i<V;i++){
	       if(inDegree[i]==0)
	       q.push(i);
	   }
	   
	   vector<int>ans;
	   
	   while(!q.empty()){
	       int node = q.front();
	       q.pop();
	       ans.push_back(node);
	       
	       for(auto it:adj[node]){
	           inDegree[it]--;
	           if(inDegree[it] == 0)q.push(it);
	       }
	   }
	    if(ans.size() != V)return true;
	    else
	        return false;
    }
};

int main()
{

 return 0;
}