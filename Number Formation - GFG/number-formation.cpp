//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {

  public:
    int getSum(int X, int Y, int Z) {
        //dp[i][j][k] = 10 * (dp[i-1][j][k] + dp[i][j-1][k] + dp[i][j][k-1]) + (4+5+6)*cnt[i-1][j][k]
        int dp[X+1][Y+1][Z+1];
        int cnt[X+1][Y+1][Z+1];
        memset(dp,0,sizeof dp);
        memset(cnt,0,sizeof cnt);
        cnt[0][0][0] = 1;
        long long ans = 0L;
        long long mod = 1e9+7;
        for(int i=0; i<=X; i++){
            for(int j=0; j<=Y; j++){
                for(int k=0; k<=Z; k++){
                    if(i > 0){
                        dp[i][j][k] = (dp[i][j][k]%mod + (10%mod * dp[i-1][j][k]%mod)%mod + (4%mod*cnt[i-1][j][k]%mod)%mod)%mod;
                        cnt[i][j][k] = (cnt[i][j][k]%mod + cnt[i-1][j][k]%mod)%mod;
                    }
                    if(j > 0){
                        dp[i][j][k] = (dp[i][j][k]%mod + (10%mod * dp[i][j-1][k]%mod)%mod + (5%mod *cnt[i][j-1][k]%mod)%mod)%mod;
                        cnt[i][j][k] = (cnt[i][j][k]%mod + cnt[i][j-1][k]%mod)%mod;
                    }
                    if(k > 0){
                        dp[i][j][k] = (dp[i][j][k]%mod + (10%mod * dp[i][j][k-1]%mod)%mod + (6%mod*cnt[i][j][k-1]%mod)%mod)%mod;
                        cnt[i][j][k] = (cnt[i][j][k]%mod + cnt[i][j][k-1]%mod)%mod;
                    }
                    ans = (ans%mod + dp[i][j][k]%mod)%mod;
                    ans %= mod;
                }
            }
        }
        return ans%mod;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;

        Solution ob;
        cout << ob.getSum(x, y, z) << "\n";
    }
    return 0;
}

// } Driver Code Ends