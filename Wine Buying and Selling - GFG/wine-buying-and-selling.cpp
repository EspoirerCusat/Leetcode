//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& Arr, int N){
      long long cost = 0;
      queue<pair<long,long>> buy,sell;
      for(int i=0; i<N; i++){
          if(Arr[i] == 0) continue;
          if(Arr[i] < 0){
              //sell
              sell.push({-Arr[i],i});
          }else{
              //buy
              buy.push({Arr[i],i});
          }
      }
      long curr = 0;
      long idx = 0;
      while(!sell.empty() or !buy.empty()){
          if(curr == 0){
              curr = sell.front().first;
              idx = sell.front().second;
              sell.pop();
          }
          if(buy.front().first > curr){
              buy.front().first -= curr;
              cost += curr * abs(buy.front().second-idx);
              curr = 0;
          }else{
              cost += buy.front().first * abs(buy.front().second-idx);
              curr -= buy.front().first;
              buy.pop();
          }
      }
      return cost;
  }
};

























//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends