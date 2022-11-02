//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            vector<int> row,col;
            row.push_back(0); row.push_back(n+1);
            col.push_back(0); col.push_back(m+1);
            for(auto& itr : enemy){
                row.push_back(itr[0]);
                col.push_back(itr[1]);
            }
            sort(row.begin(),row.end());
            sort(col.begin(),col.end());
            int ans = 0;
            // for(int i=0; i<row.size()-1; i++){
            //     for(int j=0; j<col.size()-1; j++){
            //         int r = row[i+1] - row[i] - 1;
            //         int c = col[j+1] - col[j] - 1;
            //         ans = max(ans,r*c);
            //     }
            // }
            int r = 0;
            int c = 0;
            for(int i=1; i<row.size(); i++){
                r = max(r,row[i]-row[i-1]-1);
            }
            for(int i=1; i<col.size(); i++){
                c = max(c,col[i]-col[i-1]-1);
            }
            ans = r*c;
           return ans;
        }
};


































//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends