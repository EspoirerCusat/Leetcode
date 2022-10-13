class Solution {
public:
    int n,m,k;
    int mod = 1e9+7;
    int f(vector<vector<int>>& grid,vector<vector<vector<int>>>& dp, int i, int j, int sum){
        if(i >= n or j >= m) return 0;
        if(dp[i][j][sum] != -1) return dp[i][j][sum];
        if(i == n-1 and j == m-1) return (sum%k + grid[i][j]%k)%k == 0;
        //down
        int x = f(grid,dp,i+1,j,(sum+grid[i][j])%k);
        //right
        int y = f(grid,dp,i,j+1,(sum+grid[i][j])%k);
        return dp[i][j][sum] = (x+y)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int K) {
        n = grid.size();  m = grid[0].size();
        k = K;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        return f(grid,dp,0,0,0);
    }
};