//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        int r,b,g; r = b = g = 0;
        for(int i=0; i<n; i++){
            if(a[i] == 'B') b++;
            else if(a[i] == 'R') r++;
            else g++;
        }
        if(r == n || b == n || g == n) return n;
        if((r&1 && b&1 && g&1) or (r%2 == 0 && b%2 == 0 && g%2 == 0)) return 2;
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends