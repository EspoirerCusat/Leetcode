//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int f(int x, int y){
        int cnt = 0;
        while(x > y){
            x /= 2;
            cnt++;
        }
        return cnt;
    }
    int carpetBox(int A, int B, int C, int D){
       return min(f(A,C) + f(B,D),f(A,D) + f(B,C));
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends