class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        queue<vector<int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) q.push({i,j,0});
            }
        }
        while(q.size()){
            int s = q.size();
            while(s--){
                vector<int> cur = q.front();
                q.pop();
                for(vector<int> dir:dirs){
                    int ni = cur[0]+dir[0],nj = cur[1]+dir[1];
                    if(ni<0 || nj<0 || ni>=grid.size() || nj>=grid[0].size()) continue;
                    if(grid[ni][nj]==INT_MAX){
                        grid[ni][nj] = cur[2]+1;
                        q.push({ni,nj,cur[2]+1});
                    }
                }
            }
        }
    }
};
