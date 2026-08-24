class Solution {
public:
    int ultp(int u , vector<int> & parent){
        if(parent[u] == u) return u;
        return parent[u] = ultp(parent[u] , parent);
    }

    void unionbyrank(vector<int> &parent , vector<int> &rank , int n , vector<vector<int>> &connections){
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            int pu = ultp(u , parent);
            int pv = ultp(v , parent);
            if(rank[pu] < rank[pv]){
                parent[pu] = pv;
                rank[pv] += rank[pu];
            }
            else if(rank[pv] < rank[pu]){
                parent[pv] = pu;
                rank[pu] += rank[pv];
            }
            else {
                parent[pv] = pu;
                rank[pu] += rank[pu];
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n-1) return -1;
        vector<int> parent(n);
        for(int i = 0; i < n ;i++){
            parent[i] = i;
        }
        vector<int> arr(n,0);
        unionbyrank(parent , arr , n , connections);
        
        int cables = connections.size();
        int total_grps = 0;
        int cables_used = 0;
        
        for(int i =0 ;i< n; i++){
            if(parent[i] == i){
                total_grps++;
                cables_used = cables_used + arr[i];
            }
        }
        
        cables = cables - cables_used;
        
        if(cables >= total_grps - 1) return total_grps - 1;
        else return -1;
    }
};