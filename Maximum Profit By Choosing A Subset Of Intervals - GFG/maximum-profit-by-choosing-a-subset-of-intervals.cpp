//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        sort(intervals.begin(),intervals.end());
        vector<int> dp(n+1,0);
        for(int i=0; i<n; i++){
            dp[i] = intervals[i][2];
            for(int j=0; j<i; j++){
                if(intervals[j][1] <= intervals[i][0]){
                    dp[i] = max(dp[i],intervals[i][2] + dp[j]);
                }
            }
        }
        int ans = *max_element(dp.begin(),dp.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends