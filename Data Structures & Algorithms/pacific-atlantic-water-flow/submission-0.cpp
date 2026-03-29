class Solution {
public:
    int n;
    int m;
    void dfs(vector<vector<int>>&heights, int i, int j, vector<vector<bool>>&visited){
        visited[i][j] = true;

        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for(auto &d : dir){
            int ni = i + d[0];
            int nj = j + d[1];

            if(ni >= 0 && nj >= 0 && ni <n && nj < m && !visited[ni][nj] && heights[ni][nj] >= heights[i][j]){
                dfs(heights, ni, nj, visited);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         n = heights.size();
         m = heights[0].size();

        vector<vector<bool>>pecific(n, vector<bool>(m,false));
        vector<vector<bool>>atlantic(n, vector<bool>(m,false));

        for(int i=0; i<n; i++){
            dfs(heights, i, 0, pecific);
            dfs(heights, i, m-1, atlantic);
        }

        for(int j=0; j<m; j++){
            dfs(heights, 0, j, pecific);
            dfs(heights, n-1, j, atlantic);
        }
        vector<vector<int>>result;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pecific[i][j] && atlantic[i][j]){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};
