class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        // construct graph
        unordered_map<char,unordered_set<char>> graph;
        unordered_map<char,int> indegree;
        for(string& word:words){
            for(char& c:word){
                graph[c] = {};
                indegree[c] = 0;
            }
        }
        string cur = "";
        int i = 0;
        int l = 0;
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
                    if(prev!='.' && prev!=words[j][l] && graph[prev].find(words[j][l])==graph[prev].end()){
                        graph[prev].insert(words[j][l]);
                        indegree[words[j][l]]++;
                        // cout << prev << ',' << words[j][l] << ',' << indegree[words[j][l]]<<endl;
                    }
                    prev = words[j][l];
                }else{
                    break;
                }
            }
            l++;
        }
        for(auto& node:graph){
            cout<< node.first << " : ";
            for(auto& child:node.second){
                cout << child << " ";
            }
            cout << endl;
        }

        // Starting nodes(indegree=0)
        queue<char> q;
        for(auto& c:indegree){
            if(!c.second) q.push(c.first);
        }
        string result = "";
        unordered_set<char> removed;
        while(q.size()){
            char cur = q.front();
            // cout << cur << endl;
            q.pop();
            result+=cur;
            for(char c:graph[cur]){
                indegree[c]--;
                // cout << c << ':' << indegree[c] << endl;
                if(!indegree[c] && removed.find(c)==removed.end()){
                    // cout<<c<<endl;
                    removed.insert(c);
                    q.push(c);
                }
            }
        }
        // cout << result << endl;
        if(result.size()!=graph.size()) return "";
        return result;
    }
};
