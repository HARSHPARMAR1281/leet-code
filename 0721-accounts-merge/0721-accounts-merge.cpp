class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0;i < n; i++){
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(
        vector<vector<string>>& accounts
    ) {
        unordered_map<string, int> emailId;
        unordered_map<string, string> emailName;
        int id = 0;
        for (auto& account : accounts) {
            string name = account[0];

            for (int i = 1; i < account.size(); i++) {
                string email = account[i];

                if (!emailId.count(email)) {
                    emailId[email] = id++;
                }
                emailName[email] = name;
            }
        }
        DSU dsu(id);
        for (auto& account : accounts) {
            int first = emailId[account[1]];
            for (int i = 2; i < account.size(); i++) {
                dsu.unite(first, emailId[account[i]]);
            }
        }
        unordered_map<int, vector<string>> groups;
        for (auto& [email, idx] : emailId) {
            int root = dsu.find(idx);
            groups[root].push_back(email);
        }
        vector<vector<string>> ans;
        for (auto& [root, emails] : groups) {
            sort(emails.begin(), emails.end());
            vector<string> account;
            account.push_back(emailName[emails[0]]);
            for (string& email : emails)
                account.push_back(email);
            ans.push_back(account);
        }
        return ans;
    }
};