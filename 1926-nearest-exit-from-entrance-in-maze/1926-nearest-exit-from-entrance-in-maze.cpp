class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int steps = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (!q.empty()) {
            int sz = q.size();
            steps++;

            while (sz--) {
                auto [r, c] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;
                    
                    if (maze[nr][nc] == '+')
                        continue;
                    
                    if (nr == 0 || nr == m - 1 || nc == 0 || nc == n - 1) {
                        return steps;
                    }
                    maze[nr][nc] = '+';
                    q.push({nr, nc});
                }
            }
        }
        return -1;
    }
};
