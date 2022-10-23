//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    vector<long long> res;
    void dfs(long long curr , set<long long>& st, int n, int last){
        if(n >= 9){
            return;
        }
        st.insert(curr);
        if(last < 9) dfs(curr*10 + (last+1), st, n+1, last+1);
        if(last > 0) dfs(curr*10 + (last-1), st, n+1, last-1);
    }
    Solution(){
        set<long long> st;
        for(int i=0; i<=9; i++)
            dfs(i,st,0,i);
        for(auto x : st){
            //cout<<x<<' ';
            res.push_back(x);
        }
    }
    int steppingNumbers(int n, int m)
    {
        int idx = lower_bound(res.begin(),res.end(),n) - res.begin();
        int jdx = upper_bound(res.begin(),res.end(),m) - res.begin();
        return jdx - idx;
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends