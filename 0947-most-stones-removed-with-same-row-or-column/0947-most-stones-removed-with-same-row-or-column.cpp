class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b)
            parent[b] = a;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(20005);
        for (int i = 0; i < 20005; i++) parent[i] = i;
        for (auto& stone : stones) {
            int row = stone[0];
            int col = stone[1] + 10001;
            unite(row, col);
        }
        unordered_set<int> components;
        for (auto& stone : stones) {
            components.insert(find(stone[0]));
        }
        return n - components.size();
    }
};