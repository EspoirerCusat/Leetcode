//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int arr[], int N, int K) {
        vector<int> freq(K,0);
        for(int i=0; i<N; i++){
            freq[arr[i]%K]++;
        }
        int ans = 0;
        int i = 1; int j = K - 1;
        while(i < j){
            ans += max(freq[i],freq[j]);
            i++; j--;
        }
        ans += (freq[0] > 0);
        if(K%2 == 0) ans += (freq[K/2] > 0);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends