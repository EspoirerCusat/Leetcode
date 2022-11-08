//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long x = 0L;
        for(int i=0; i<N; i++){
            x ^= Arr[i];
        }
        int cnt = 0;
        while((x&1) == 0){
            cnt++;
            x >>= 1;
        }
        long long num1 = 0L;
        for(int i=0; i<N; i++){
            if(Arr[i]&(1<<cnt)){
                num1 ^= Arr[i];
            }
        }
        vector<long long> ans; ans.push_back(num1);
        for(int i=0; i<N; i++){
            num1 ^= Arr[i];
        }
        ans.push_back(num1);
        sort(ans.begin(),ans.end(),greater<long long>());
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
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends