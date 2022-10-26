//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        vector<char> st;
        for(int i=0; i<n; i++){
            if(st.size() > 0){
                if(st.back() == a[i]){
                    st.push_back(a[i]);
                }else{
                    if(st.back() == 'R'){
                        if(a[i] == 'B'){
                            st.pop_back();
                            st.push_back('G');
                        }else{
                            st.pop_back();
                            st.push_back('B');
                        }
                    }else if(st.back() == 'B'){
                        if(a[i] == 'R'){
                            st.pop_back();
                            st.push_back('G');
                        }else{
                            st.pop_back();
                            st.push_back('R');
                        }
                    }else{
                        if(a[i] == 'B'){
                            st.pop_back();
                            st.push_back('R');
                        }else{
                            st.pop_back();
                            st.push_back('B');
                        }
                    }
                }
                while(st.size() >= 2 && st[st.size()-1] != st[st.size()-2]){
                    if(st[st.size()-1] == 'R'){
                        if(st[st.size()-2] == 'B'){
                            st.pop_back();
                            st.pop_back();
                            st.push_back('G');
                        }else{
                            st.pop_back();
                            st.pop_back();
                            st.push_back('B');
                        }
                    }else if(st[st.size()-1] == 'B'){
                        if(st[st.size()-2] == 'R'){
                            st.pop_back();
                            st.pop_back();
                            st.push_back('G');
                        }else{
                            st.pop_back();
                            st.pop_back();
                            st.push_back('R');
                        }
                    }else{
                        if(st[st.size()-2] == 'B'){
                            st.pop_back();
                            st.pop_back();
                            st.push_back('R');
                        }else{
                            st.pop_back();
                            st.pop_back();
                            st.push_back('B');
                        }
                    }
                }
            }else{
                st.push_back(a[i]);
            }
        }
        return st.size()&1 ? 1 : 2;
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