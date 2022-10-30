//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	    vector<long long int> v(n+10,0);
	    v[1] = 1; v[7] = -1;
	    for(int i=1; i<=n; i++){
	        v[i] += v[i-1];
	        v[i+1] += 2*v[i];
	        v[i+6] += -2*v[i];
	    }
	    return v[n];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends