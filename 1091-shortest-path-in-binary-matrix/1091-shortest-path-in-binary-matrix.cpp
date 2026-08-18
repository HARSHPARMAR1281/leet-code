class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> distance(grid.size(),vector<int>(grid.size() , 1e9));
        priority_queue<pair<int,pair<int , int> > , vector<pair<int,pair<int , int> > > , greater<pair<int,pair<int , int> > > > pq;
        pq.push( { 1 , { 0 , 0 } } );
        distance[0][0] =1;
        if(grid[0][0] == 1) return -1;    
        int dr[] = { -1 , -1 , 0 , 1 , 1 , 1 , 0 , -1 };
        int dc[] = { 0 , 1 , 1 , 1 , 0 , -1 , -1 , -1 };
        while(!pq.empty()){
            int dist = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            for(int i =0 ; i< 8 ; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == 0 && distance[nr][nc] > dist + 1){
                    distance[nr][nc] = dist + 1;
                    pq.push( { distance[nr][nc] , { nr , nc } } );
                }
            }


        }
        int n = grid.size();
    
        if(distance[ n-1 ][ n - 1 ] == 1e9) return -1;
        else return distance[ n-1 ][ n - 1 ];
    }
};