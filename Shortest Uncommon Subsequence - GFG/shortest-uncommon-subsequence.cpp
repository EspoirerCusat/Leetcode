//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int f(string& S, string& T, int n, int m, vector<vector<int>>& dp){
        if(n == 0) return 1e8;
        if(m == 0) return 1;
        if(dp[n][m] != -1) return dp[n][m];
        int idx = -1;
        for(int i=m-1; i>=0; i--){
            if(S[n-1] == T[i]){
                idx = i;
                break;
            }
        }
        if(idx == -1) return dp[n][m] = 1;
        
        int ans = min(1+f(S,T,n-1,idx,dp),f(S,T,n-1,m,dp));
        
        return dp[n][m] = ans;
    }
    int shortestUnSub(string S, string T) {
        int n = S.size(); int m = T.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int ans = f(S,T,n,m,dp);
        return ans >= 1e8 ? -1 : ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends