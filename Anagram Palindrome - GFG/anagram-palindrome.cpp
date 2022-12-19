//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int isPossible (string s);

int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		if (isPossible (s))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int isPossible (string S)
{
    int arr[26] = {0};
    for(int i=0; i<S.size(); i++){
        arr[S[i] - 'a']++;
    }
    int cnt = 0;
    for(int i=0; i<26; i++){
        if(arr[i]%2 != 0){
            cnt++;
        }
    }
    if(cnt > 1) return 0; //false
    return 1; //true
}
