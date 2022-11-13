//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalWays(int n, vector<int>capacity) {
        int mod = 1e9 + 7;
        sort(begin(capacity),end(capacity));
        long long ans = capacity[0];
        for(int i=1; i<n; i++){
            ans = (ans%mod * (capacity[i]-i >= 0 ? capacity[i]-i : 0)%mod)%mod;
        }
        return (int)ans%mod;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>capacity(n);
		for(int i = 0; i < n; i++)
			cin >> capacity[i];
		Solution ob;
		int ans = ob.totalWays(n, capacity);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends