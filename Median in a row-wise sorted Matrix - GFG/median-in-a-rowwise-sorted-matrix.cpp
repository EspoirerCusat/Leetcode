//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{   
public:
    //int arr[10000000];
    int median(vector<vector<int>> &matrix, int R, int C){
        int mn = INT_MAX; int mx = INT_MIN;
        for(int i=0; i<R; i++){
            mn = min(matrix[i][0],mn);
            mx = max(matrix[i][C-1],mx);
        }
        long long int d = (R*C+1)/2;
        long long int ans = INT_MAX;
        while(mn <= mx){
            long long mid = (mn + mx)/2;
            long long  cnt = 0;
            for(int i=0; i<R; i++){
                cnt += upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();
            }
            if(cnt < d){
                mn = mid+1;
            }else{
                ans = mid;
                mx = mid-1;
            }
        }
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
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends