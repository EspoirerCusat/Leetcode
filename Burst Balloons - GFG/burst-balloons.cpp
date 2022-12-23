//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int f(vector<int>& arr, vector<vector<int>>& dp, int i, int j){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        for(int k=i; k<=j; k++){
            int res = arr[i-1] * arr[k] * arr[j+1] + f(arr,dp,i,k-1) + f(arr,dp,k+1,j);
            ans = max(ans,res);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(int N, vector<int> &arr) {
        arr.insert(arr.begin(),1);
        arr.push_back(1);
        vector<vector<int>> dp(N+2,vector<int>(N+2,-1));
        return f(arr,dp,1,N);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends