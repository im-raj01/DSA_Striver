#include<bits/stdc++.h>
using namespace std;

class solution{
    private:
    void dfs(int node,vector<int>adj[], int vis[], vector<int>&ls){
        vis[node] = 1;
        ls.push_back(node);// ans store kar liya
        // traverse all the neighbours:
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,ls);
            }
        }
    }

    public:
    vector<int>dfsTraversal(int N,vector<int>adj[]){
        int vis[N] = {0};
        int start = 0;

        vector<int>ls; // to store the dfs;
        dfs(start,adj,vis,ls);
        return ls;
    }

};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}
int main(){
    vector <int> adj[5];
    
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    solution obj;
    vector <int> ans = obj.dfsTraversal(5, adj);
    printAns(ans);

    return 0;
}