//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
    long long int fact[100010];
    long long int fact_inv[100010];
    int mod = 1e9+7;
    int power(long long int a, long long int b,long long int mod){
        if(b == 1) return a;
        if(b == 0) return 1;
        long long int ans = power(a,b/2,mod)%mod;
        ans = (ans%mod * ans%mod)%mod;
        ans %= mod;
        if(b&1) ans = (ans%mod * a%mod)%mod;
        ans %= mod;
        return ans%mod;
    }
    int mod_inv(int a, int m){
        //cout<<power(a,m-2,m)%mod<<" ";
        return power(a,m-2,m)%mod;
    }
    int ncr(int n, int r){
        if(r > n) return 0;
        return (fact[n]%mod*(fact_inv[r]%mod*fact_inv[n-r]%mod)%mod)%mod;
    }
    void pree(){
        int N = 100010;
        fact[0] = 1;
        for(int i=1; i<N; i++){
            fact[i] = (fact[i-1]%mod * i%mod)%mod;
            fact[i] %= mod;
        }
        //cout<<fact[N-1]<<" ";
        fact_inv[N-1] = mod_inv(fact[N-1],mod)%mod;
        //cout<<fact_inv[N-1]<<" ";
        for(int i=N-2; i>=0; i--){
            fact_inv[i] = (fact_inv[i+1]%mod*(i+1)%mod)%mod;
        }
    }
	int compute_value(int n)
	{
	    pree();
	    //for(int i=0; i<10; i++) cout<<fact_inv[i]<<" ";
	    int ans = ncr(2*n,n);
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends