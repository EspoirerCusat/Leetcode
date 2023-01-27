//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

long long mod = 1e9 + 7;
long long fx(string S, int i, long long dp[]){
        if(i >= S.size()){
            return 1;
        }
        if(dp[i] != -1) return dp[i];
        long long f1,f2; 
        f1 = f2 = false;
        long long num = int(S[i] - '0');
        long long ans = 0;
        if(num >= 1 && num <= 9){
            f1 = true;
            ans = fx(S,i+1,dp)%mod;
        }
        if(i+1 < S.size()){
            num = int(S[i] - '0')*10 + int(S[i+1] - '0');
            if(num >= 10 && num <= 26){
                f2 = true;
                ans = (ans%mod + fx(S,i+2,dp))%mod;
            }
        }
        if(!f1 && !f2) return dp[i] = 0;
        return dp[i] = ans;
}
class Solution {
	public:
		int CountWays(string str){
		long long dp[str.size()+1];
        for(long long i=0; i<=str.size(); i++) dp[i] = -1;
        long long ans = fx(str,0,dp);
        if(ans < 0) return 0;
        return ans%mod;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends