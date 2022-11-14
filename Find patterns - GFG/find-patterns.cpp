//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string S, string W){
        int n = S.size(); 
        vector<bool> vis(n,0);
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(S[i] == W[0] && !vis[i]){
                vis[i] = 1;
                int idx = 1;
                for(int j=i+1; j<n; j++){
                    if(idx < W.size() && S[j] == W[idx] && !vis[j]){
                        idx++;
                        vis[j] = 1; 
                    }
                }
                if(idx >= W.size()) cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends