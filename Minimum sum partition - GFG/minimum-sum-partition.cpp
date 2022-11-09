//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    int f(int i, int curr, int sum, int arr[],vector<vector<int>>& dp){
        if(i <= 0) return abs(sum-2*curr);
        if(dp[i][curr] != -1) return dp[i][curr];
        //take it
        int ans = min(f(i-1,curr+arr[i-1],sum,arr,dp),f(i-1,curr,sum,arr,dp));
        return dp[i][curr] = ans;
    }
	int minDifference(int arr[], int n)  { 
	    //vector<vector<int>> dp(n,vector<int>(n,-1));
	    int sum = 0;
	    for(int i=0; i<n; i++) sum += arr[i];
	    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
	    return f(n,0,sum,arr,dp);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends