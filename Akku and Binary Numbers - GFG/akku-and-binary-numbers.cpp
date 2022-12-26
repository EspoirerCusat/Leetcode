//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    vector<long long> v;
    void precompute()
    {
        for(int i=0; i<63; i++){
            for(int j=i+1; j<63; j++){
                for(int k=j+1; k<63; k++){
                    long long val = (1LL<<i) + (1LL<<j) + (1LL<<k);
                    v.push_back(val);
                }
            }
        }
        sort(v.begin(),v.end());
    }
    
    long long solve(long long l, long long r){
        int idx = lower_bound(v.begin(),v.end(),l) - v.begin();
        int jdx = upper_bound(v.begin(),v.end(),r) - v.begin();
        return jdx-idx;
    }
    
};
























//{ Driver Code Starts.

int main()
{
    int t;
    Solution ob;
    ob.precompute();
    cin>>t;
    while(t--)
    {
        long long l,r;
        cin>>l>>r;
        cout << ob.solve(l, r) << endl; 
    }
    return 0;
}
// } Driver Code Ends