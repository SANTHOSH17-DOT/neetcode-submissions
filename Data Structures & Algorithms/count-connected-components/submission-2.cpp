class DSU {
    public:
        vector<int> parents;
        vector<int> sizes;
        DSU(int n){
            for(int i=0;i<n;i++) parents.push_back(i);
            for(int i=0;i<n;i++) sizes.push_back(1);
        }
        int find(int i){
            if(parents[i]==i) return i;
            return find(parents[i]);
        }
        void merge(int i,int j){
            int pi=find(i),pj=find(j);
            if(sizes[pi]>sizes[pj]){
                parents[pj]=pi;
                sizes[pi] += sizes[pj];
            }else{
                parents[pi]=pj;
                sizes[pj] += sizes[pi];
            }
        }
};
class Solution {
public:

    int countComponents(int n, vector<vector<int>>& edges) {
        DSU* dsu = new DSU(n);
        for(vector<int>& edge:edges){
            dsu->merge(edge[0],edge[1]);
        }
        int result = 0;
        for(int i=0;i<n;i++){
            if(i==dsu->parents[i]) result++;
        }
        return result;
    }
};
