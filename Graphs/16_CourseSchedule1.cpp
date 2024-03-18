#include<bits/stdc++.h>
using namespace std;
#define ll long long

// link: https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        int n = prerequisites.size();
        vector<int>adj[numCourses];
       for(int i = 0;i<n;i++){
            vector<int>v = prerequisites[i];
            adj[v[1]].push_back(v[0]);
       }
        // toposort:
       int inDegree[numCourses]; // to store the indegree of all nodes:
       for(int i = 0;i<numCourses;i++){
        inDegree[i] = 0;
       }
	   for(int i = 0;i<numCourses;i++){
	       for(auto it:adj[i]){
	           inDegree[it]++;
	       }
	   }
	   
	   queue<int>q;
	   for(int i = 0;i<numCourses;i++){
	       if(inDegree[i]==0)
	       q.push(i);
	   }
	   
	   vector<int>topo;
	   
	   while(!q.empty()){
	       int node = q.front();
	       q.pop();
	       topo.push_back(node);
	       
	       for(auto it:adj[node]){
	           inDegree[it]--;
	           if(inDegree[it] == 0)q.push(it);
	       }
	   }
	    if(topo.size() == numCourses)return true;
	    else
	        return false;

        
    }
};
int main()
{

 return 0;
}