class Solution {
public:
    int networkDelayTime(vector<vector<int>>& elist, int n, int k) {
        vector< vector< pair< int , int> >> adj(n+1);
        for(auto it : elist){
            adj[ it[0] ].push_back( {it[1] , it[2] } );
        }
        vector<int> dist(n+1 , 1e9);
        priority_queue< pair<int , int> , vector<pair <int , int>> , greater <pair <int , int>>> pq;
        pq.push({0 , k});
        dist[k] = 0;
        while( !pq.empty() ) {
           int cost = pq.top().first;
           int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                if(dist[it.first ] > cost + it.second){
                    dist[it.first] = cost + it.second;
                    pq.push( {dist[it.first] , it.first } );
                }
            }
        }
        int max_time = -1;
        for(int i = 1; i < n+1 ; i++){
            if(dist[i] == 1e9) return -1;
            else max_time = max(max_time , dist[i]);
            
            
        }
        return max_time;


        //return 0;
    }
};