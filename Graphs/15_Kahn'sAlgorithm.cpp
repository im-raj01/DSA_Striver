#include<bits/stdc++.h>
using namespace std;
#define ll long long

// link: https://www.geeksforgeeks.org/problems/topological-sort/1
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