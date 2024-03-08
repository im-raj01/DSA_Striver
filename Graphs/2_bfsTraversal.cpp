#include<bits/stdc++.h>
using namespace std;

// q_link: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
class solution{
  public:
// no of nodes = N:
  vector<int>bfsTraversal(int N,vector<int>adj[]){
    int vis[N] = {0};
    vis[0] =1;
    queue<int>q;
    vector<int>ans;

    q.push(0);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
        
    }
    return ans;
  }  
};

void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);

}
int main(){
    vector<int>adj[6];
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,0,4);

    solution obj;

    vector<int>ans = obj.bfsTraversal(5,adj);

    // printing the ans after traversal:
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;

}