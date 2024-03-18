/*Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices
 such that for every directed edge u-v, vertex u comes before v in the ordering.

Note: Topological Sorting for a graph is not possible if the graph is not a DAG.*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

// link: https://www.geeksforgeeks.org/problems/topological-sort/1

// USING DFS:
class Solution
{
    private:
    void dfs(int node,int vis[],vector<int> adj[],stack<int> &st){
        vis[node] = 1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,st);
            }
        }
        st.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int vis[V] = {0};
	    stack<int>st;
	    vector<int>ans;
	    
	    for(int i = 0;i<V;i++){
	        if(!vis[i]){
	  
	            dfs(i,vis,adj,st);
	        }
	    }
	    
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	    
	}
};

// using BFS:
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	   // Using kahn's algorithm (using BFS)
	   
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
	    return ans;
	}
};
int main()
{

 return 0;
}