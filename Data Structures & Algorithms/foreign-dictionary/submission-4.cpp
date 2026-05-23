class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        // construct graph
        unordered_map<char,unordered_set<char>> graph;
        string cur = "";
        int i = 0;
        int l = 0;
        unordered_set<char> withParents;
        while(i<words.size()){
            // cout << words[i] << endl;
            if(cur.length()==words[i].length()){
                i++;
                cur = "";
                l = 0;
            }
            if(i==words.size()) break;
            char prev = '.';
            cur = words[i].substr(0,l);
            for(int j=i;j<words.size();j++){
                // Handle ["wrtkj","wrt"]
                if(i!=j && words[j].length()==l && cur==words[j].substr(0,l)) return "";
                if(words[j].length()>l && cur==words[j].substr(0,l)){
                    if(prev!=words[j][l]){
                        graph[prev].insert(words[j][l]);
                        if(prev!='.') withParents.insert(words[j][l]);
                    }
                    prev = words[j][l];
                }else{
                    break;
                }
            }
            l++;
        }
        // remove nodes with parents from '.''s children list
        // starting nodes
        for(char c:withParents){
            graph['.'].erase(c);
        }
        // for(auto& node:graph){
        //     cout<< node.first << " : ";
        //     for(auto& child:node.second){
        //         cout << child << " ";
        //     }
        //     cout << endl;
        // }
        unordered_map<char,int> visited;
        for(string& word:words){
            for(char& c:word){
                visited[c] = 0;
            }
        }

        // Add disconnected nodes
        string result = "";
        for(char c:graph['.']){
            string tmp = dfs(c,visited,graph);
            if(tmp=="-1") return "";
            result += tmp;
        }
        // Invalid sequence
        if(result.size()!=visited.size()) return "";
        return result;
    }
    string dfs(char cur,unordered_map<char,int>& visited,unordered_map<char,unordered_set<char>>& graph){
        // Loop detected
        if(visited[cur]==1) return "-1";

        // trail node
        if(visited[cur]==2) return "";
        if(!graph[cur].size()){
            visited[cur] = 2;
            return string(1,cur);
        }

        visited[cur]=1;
        // cout << "cur: " << cur << endl;
        string t = "";
        for(auto& child:graph[cur]){
            string res = dfs(child,visited,graph);
            if(res=="-1") return "-1";
            // cout << res << endl;
            t = res + t;
        }
        visited[cur] = 2;
        // cout << cur+t << endl;
        // cout << "=====" << endl;
        return cur+t;
    }
};
