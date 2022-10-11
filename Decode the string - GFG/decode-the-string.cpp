//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    string decodedString(string s){
        stack<int> istk;
        stack<char> sstk;
        int n = s.size();
        for(int i=-0; i<n; i++){
            int cnt = 0;
            if(s[i] >='0' && s[i] <= '9'){
                while(s[i] >='0' && s[i] <= '9'){
                    cnt = cnt*10 + (s[i] - '0');
                    i++;
                }
                i--;
                istk.push(cnt);
            }else if(s[i] == ']'){
                string t = "";
                cnt = 0;
                if(!istk.empty()){
                    cnt = istk.top(); istk.pop();
                }
                while(!sstk.empty() && sstk.top() != '['){
                    t = sstk.top() + t;
                    sstk.pop();
                }
                if(!sstk.empty() && sstk.top() == '['){
                    sstk.pop();
                }
                
                string ans = "";
                for(int j=0; j<cnt; j++) ans += t;
                for(int j=0; j<ans.size(); j++) sstk.push(ans[j]);
                
            }else if(s[i] == '['){
                if(s[i-1] >= '0' && s[i-1] <= '9'){
                    sstk.push(s[i]);
                }else{
                    sstk.push(s[i]);
                    istk.push(1);
                }
            }else{
                sstk.push(s[i]); //a....z
            }
        }
        string ss = "";
        while(!sstk.empty()){
            ss = sstk.top() + ss;
            sstk.pop();
        }
        return ss;
    }
};























//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends