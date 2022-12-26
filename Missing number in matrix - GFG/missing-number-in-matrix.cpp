//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    long long int MissingNo(vector<vector<int> >& matrix) {
       
       int n = matrix.size();
       int m = matrix[0].size();
       int idx,jdx;
       
       for(int i=0; i<n; i++){
           for(int j=0; j<m; j++){
               if(matrix[i][j] == 0){
                   idx = i; jdx = j;
                   break;
               }
           }
       }
       
       
       
       long long sum = 0;
       
       if(idx == 0){
           for(int j=0; j<m; j++) sum += (long long)matrix[1][j];
       }else{
           for(int j=0; j<m; j++) sum += (long long)matrix[0][j];
       }
       
       long long req = 0;
       for(int i=0; i<m; i++) req += (long long)matrix[idx][i];
       
       if(req >= sum) return -1;
       
       long long x = sum - req;
       //cout<<x<<"\n";
       //matrix[idx][jdx] = x;
       vector<vector<long long>> matrixx(n,vector<long long>(m));
       
       for(int i=0; i<n; i++){
           for(int j=0; j<m; j++){
               if(matrix[i][j] == 0){
                   matrixx[i][j] = x;
               }else{
                   matrixx[i][j] = matrix[i][j];
               }
           }
       }
       
       //check --- 1
       set<long long> s;
       for(int i=0; i<n; i++){
           long long res = 0;
           for(int j=0; j<m; j++){
               res += (long long)matrixx[i][j];
           }
           //cout<<res<<",";
           s.insert(res);
       }
       //cout<<"\n";
       //check --- 2
       for(int j=0; j<m; j++){
           long long res = 0;
           for(int i=0; i<n; i++){
               res += (long long)matrixx[i][j];
           }
           //cout<<res<<",";
           s.insert(res);
       }
       
       //check --- 3
       int i=0; int j=0;
       long long res = 0;
       while(i < n && j < m){
           res += (long long)matrixx[i][j];
           i++; j++;
       }
       s.insert(res);
       //cout<<res<<"\n";
       //check --- 4
       i = 0; j = m-1;
       long long res1 = 0;
       while(i < n && j >= 0){
           res1 += (long long)matrixx[i][j];
           i++; j--;
       }
       s.insert(res1);
    
       //cout<<res1<<"\n";
    //   for(auto itr = s.begin(); itr != s.end(); itr++){
    //       cout<<(*itr)<<",";
    //   }
       if(s.size() == 1) return x;
       return -1;
    }
    
};


























//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends