#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isDetect(int start_node, vector<int> adj[],int vis[]){
         vis[start_node] = 1;
         queue<pair<int,int>>q; // start_node,parent
         q.push({start_node,-1});

         while(!q.empty()){
             int node = q.front().first;
             int parent = q.front().second;

             q.pop();
             
             for(auto it: adj[node]){
                 //it = adjacent node;
                 if(!vis[it]){
                     vis[it] = 1;
                     q.push({it,node});
                 }
                 else if(parent != it){
                     return true;
                 }
             }
         }
         return false;

    }

     bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        for(int i = 0;i<V;i++){
            if(!vis[i]){
               if(isDetect(i,adj,vis))return true;
            }
        }
        return false;
}


// USING DFS: M-2:
bool isDetect(int node,int parent, vector<int>adj[],int vis[]){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                // dfs Call:
                if(isDetect(it,node,adj,vis))return true;;
            }
            else if(it != parent){
                return true;
            }
        }
        return false;
        
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                if(isDetect(i,-1,adj,vis))return true;
            }
        }
        return false;
        
        
        
    }

int main()
{

 return 0;
}