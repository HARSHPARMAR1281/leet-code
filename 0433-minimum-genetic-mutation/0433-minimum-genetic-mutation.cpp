class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set< string > bankset(bank.begin() , bank.end());
        unordered_set< string > visited;

        queue<string> q;
        q.push(startGene);
        visited.insert(startGene);
        int level = 0;

        while(!q.empty()){
            int n = q.size();
            while(n--){
                string word = q.front();
                q.pop();
                if(word == endGene) return level;
                for(char ch : "ACGT"){
                    
                    for(int i = 0 ; i< 8 ;i++){
                        string neighbour = word;
                        neighbour[i] = ch;

                        if(bankset.find(neighbour) != bankset.end() && visited.find(neighbour) == visited.end()){
                            visited.insert(neighbour);
                            q.push(neighbour);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
     }
};