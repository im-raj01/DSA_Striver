#include<bits/stdc++.h>
using namespace std;
#define ll long long

// link -> 
// link -> https://leetcode.com/problems/is-graph-bipartite/
class Solution {
public:
    bool bfs(int start, int V, vector<vector<int>>& adj,int color[]){
    
        queue<int>q;
	    q.push(start);
	    
	    
	    color[start] = 0;
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        for(auto it:adj[node]){
	            if(color[it] == -1){
	                q.push(it);
	                color[it] = !color[node];
	                
	            }
	            else if(color[it] == color[node]){
	                return false;
	            }
	        }
	        
	    }
	    return true;
}

    bool isBipartite(vector<vector<int>>& graph) {
        int V= graph.size();
        int color[V];
	    for(int i = 0;i<V;i++)color[i] = -1;
	    for(int i = 0;i<V;i++){
	        if(color[i] == -1){
	            if(bfs(i,V,graph,color)==false)return false;
	        }
	    }
	    return true;
    }
};
int main()
{

 return 0;
}