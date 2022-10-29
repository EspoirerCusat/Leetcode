//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        set<string> st;
        for(int i=0; i<n; i++) st.insert(contact[i]);
        vector<vector<string>> v;
        for(int i=0; i<s.size(); i++){
            vector<string> t;
            for(auto itr : st)
                if(s.substr(0,i+1) == itr.substr(0,i+1)) 
                    t.push_back(itr);
            if(t.size() == 0) t.push_back("0");
            v.push_back(t);
        }
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends