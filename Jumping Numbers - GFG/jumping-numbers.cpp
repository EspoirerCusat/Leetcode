//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long jumpingNums(long long X) {
        if(X < 10) return X;
        //try all possible answer
        long long ans = 0;
        for(int i=1; i<=9; i++){
            queue<long long> q;
            q.push(i);
            while(!q.empty()){
                long long x = q.front(); q.pop();
                if(x <= X){
                    ans = max(ans,x);
                }else{
                    continue;
                }
                if(x%10 != 9){
                    q.push(x*10 + x%10 +1);
                }
                if(x%10 != 0){
                    q.push(x*10 + x%10 -1);
                }
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends