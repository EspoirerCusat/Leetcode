//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    int fillingBucket(int N) {
        if(N <= 2) return N;
        int mod = 1e8;
        int a = 1;
        int b = 2;
        int c = 0;
        for(int i=3; i<=N; i++){
            c = (a + b)%mod;
            a = b;
            b = c;
        }
        return c;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends