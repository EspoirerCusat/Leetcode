//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        int i = 0; int j = -1;
        vector<vector<int>> vis(R,vector<int>(C,1));
        vector<int> res;
        while(true){
            j += 1;
            bool f1,f2,f3,f4; 
            f1 = f2 = f3 = f4 = true;
            while(i < R && j < C && vis[i][j]){
                res.push_back(a[i][j]);
                vis[i][j] = 0;
                j++;
                f1 = false;
            }
            j--; i++;
            while(i < R && j < C && vis[i][j]){
                res.push_back(a[i][j]);
                vis[i][j] = 0;
                i++;
                f2 = false;
            }
            i--; j--;
            while(i < R && j >= 0 && vis[i][j]){
                res.push_back(a[i][j]);
                vis[i][j] = 0;
                j--;
                f3 = false;
            }
            i--; j++;
            while(i >= 0 && j < C && vis[i][j]){
                res.push_back(a[i][j]);
                vis[i][j] = 0;
                i--;
                f4 = false;
            }
            i++;
            if(f1 && f2 && f3 && f4) break;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends