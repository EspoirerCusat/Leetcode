//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class node{
    public:
    node* t[26];
    bool isEnd;
    node(){
        for(int i=0; i<26; i++){
            t[i] = NULL;
        }
        isEnd = false;
    }
};



class Solution
{
public:
    bool insert_trie(node* root,string& s){
        
        bool flag = true;
        node* temp = root;
        for(int i=0; i<s.size(); i++){
            if(!temp->isEnd) flag = false;
            if(temp->t[s[i]-'a'] == NULL) temp->t[s[i]-'a'] = new node();
            temp = temp->t[s[i]-'a'];
        }
        temp->isEnd = true;
        
        return flag;
    }
    
    static bool comp(const string& a, const string& b){
        if(a.size() == b.size()) return a < b;
        
        return a.size() < b.size();
    }
    
    string longestString(vector<string> &words)
    {
        sort(words.begin(),words.end(),comp);
        string s = "";
        node* root = new node();
        root->isEnd = true;
        for(int i=0; i<words.size(); i++){
            bool f = insert_trie(root,words[i]);
            if(f && words[i].size() > s.size()){
                s = words[i];
            }
        }
        return s;
    }
};





















//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends