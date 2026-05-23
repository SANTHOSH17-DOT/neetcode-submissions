class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adjacency(n);
        for(vector<int>& e:edges){
            adjacency[e[0]].insert(e[1]);
            adjacency[e[1]].insert(e[0]);
        }
        vector<bool> visited(n,false);
        queue<int> q;
        int count = 0;
        q.push(0);
        while(q.size()){
            int cur = q.front();
            cout << cur << endl;
            visited[cur] = true;
            count++;
            q.pop();
            for(int node:adjacency[cur]) {
                // Remove cur from node's adjacency(pending)
                adjacency[node].erase(cur);
                if(visited[node]) return false;
                q.push(node);
            }
        }
        cout << "count: "<< count<<endl;
        if(count!=n) return false;
        return true;
    }
    
};
