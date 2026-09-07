class Solution {
public:

    bool bfs(vector<vector<int>>& adj, int v, vector<int> &color ){
        queue<int> q;
        q.push(v);
        color[v] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it: adj[node]){
                if(color[it] == color[node]) return false;
                else if(color[it] == -1) {
                    q.push(it);
                    color[it] = 1-color[node];
                }
            }
        }
        return true;

    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto it: dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> color(n+1,-1);
        bool output = false;
        for(int i = 1; i <= n; i++){
            if(color[i] == -1){
                if(bfs(adj, i, color) == false) return false;
            }
        }
        return true;
    }
};