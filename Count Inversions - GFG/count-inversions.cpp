//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

struct fenwick{
    int n;
    vector<long long> fn;
    fenwick(int n){
        this->n = n+1;
        fn.resize(this->n,0);
    }
    //update
    void add(int x, int y){
        x++;
        while(x < n){
            fn[x] += y;
            x += (x & (-x)); //add last set bit
        }
    }
    //query
    long long sum(int x){
        x++;
        long long ans = 0; 
        while(x > 0){
            ans += fn[x];
            x -= (x & (-x)); //remove last set bit
        }
        return ans;
    }
    long long sum(int l, int r){
        return sum(r) - sum(l-1);
    }
};

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        fenwick fen(N);
        vector<pair<long long,int>> a; //{val,idx}
        for(int i=0; i<N; i++){
            a.push_back({arr[i],i});
        }
        sort(a.begin(),a.end());
        long long cnt = 0;
        for(int i=0; i<N; i++){
            cnt += fen.sum(a[i].second+1,N-1);
            fen.add(a[i].second,1);
        }
        
        return cnt;
        
    }

};















//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends