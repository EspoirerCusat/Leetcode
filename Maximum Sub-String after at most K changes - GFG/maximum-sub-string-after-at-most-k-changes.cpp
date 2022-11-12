//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    
		    int ans = 0;
		    for(char ch = 'A'; ch <= 'Z'; ch++){
		        int i = 0; int j = 0;
		        int sum = 0;
		        int extra = 0;
		        while(j < s.size()){
		            if(s[j] != ch){
		                extra++;
		                while(extra > k){
		                    if(s[i] != ch) extra--;
		                    i++;
		                }
		            }
		            sum = max(sum,j-i+1);
		            j++;
		        }
		        ans = max(ans,sum);
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends