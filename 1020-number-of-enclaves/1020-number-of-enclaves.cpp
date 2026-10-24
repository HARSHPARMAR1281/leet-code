class Solution {
public:
    void dfs(int r,int c ,vector<vector<int>>& board,vector<vector<int>>& vis,int dr[],int dc[] ){
        int m = board.size();
        int n = board[0].size();
        vis[r][c]=1;

        for(int i =0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr<m&&nr>=0&&nc<n&&nc>=0&&vis[nr][nc]==0&&board[nr][nc]==1){
                dfs(nr,nc,board,vis,dr,dc);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& board) {
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i =0;i<n;i++){
            if(board[0][i]==1) dfs(0,i,board,vis,dr,dc);
        }
        for(int i =0;i<m;i++){
            if(board[i][0]==1) dfs(i,0,board,vis,dr,dc);
        }
        for(int i =0;i<n;i++){
            if(board[m-1][i]==1) dfs(m-1,i,board,vis,dr,dc);
        }
        for(int i =0;i<m;i++){
            if(board[i][n-1]==1) dfs(i,n-1,board,vis,dr,dc);
        }
        int count =0;

        for(int i  =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(board[i][j]==1&&vis[i][j]==0){
                    count++;
                }
            }
        }
        return count;
    }
};