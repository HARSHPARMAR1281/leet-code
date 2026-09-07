class Solution {
public:
    
    bool check(int n, vector<vector<int>> &adj, vector<int> &vis, int node, int dest){
        if(node == dest) return true;
        if(vis[node]) return false;
        vis[node ] = true;
        for(auto it: adj[node]){
            if(check(n, adj, vis, it, dest) == true) return true;
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        queue<int> q;
        vector<int> vis(n , 0);
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return check(n, adj, vis, source, destination);

        // BFS


        // q.push(source);
        // while(!q.empty()){
        //     int n = q.size();
        //     while(n--){
        //         int node = q.front();
        //         q.pop();

        //         if(node == destination) return true;

        //         for(auto it: adj[node]){
        //             if(!vis[it]) {
        //                 vis[it] = 1;
        //                 q.push(it);
        //             }
        //         }
        //     }
        // }
        // return false;
    }
};