class Solution {
public:

    void dfs(vector<vector<int>> &adj, int node, vector<bool> &vis){
        vis[node] = true;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(adj, it, vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size() , false);
        dfs(rooms, 0, vis);
        for(auto it: vis){
            if(it == false ) return false;
        }
        return true;
    } 
};