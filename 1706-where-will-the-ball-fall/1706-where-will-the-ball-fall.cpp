class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int n = grid.size(); int m = grid[0].size();
        vector<int> ans(m,-1);
        for(int k=0; k<m; k++){
            bool flag = true;
            int jdx = k;
            int idx = 0;
            while(idx < n && jdx < m){
                if(jdx+1 < m && grid[idx][jdx] == 1 && grid[idx][jdx+1] == 1){
                    idx++; jdx++;
                    continue;
                }
                if(jdx-1 >= 0 && grid[idx][jdx] == -1 && grid[idx][jdx-1] == -1){
                    idx++; jdx--;
                    continue;
                }
                flag = false;
                break;
            }
            // if(flag) ans.push_back(1);
            // else ans.push_back(-1);
            if(flag){
                ans[k] = jdx;
            }
        }
        return ans;
    }
};