//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
       queue<pair<long long int,pair<int,int>>> q;
       q.push({0,source});
       int n = grid.size(); int m = grid[0].size();
       int ans = 1;
       grid[source.first][source.second] = 0;
       while(q.size() > 0){
           auto node = q.front(); q.pop();
           if(node.second == destination){
               return node.first;
           }
           int i = node.second.first;
           int j = node.second.second;
           grid[i][j] = 0;
           int dx[] = {-1,0,1,0};
           int dy[] = {0,1,0,-1};
           for(int k=0; k<4; k++){
               int idx = i + dx[k]; int jdx = j + dy[k];
               if(idx < 0 or jdx < 0 or idx >= n or j >= m) continue;
               if(grid[idx][jdx] == 1){
                   grid[idx][jdx] = 0;
                   q.push({node.first+1,{idx,jdx}});
               }
           }
           
       }
       return -1;
    }
};






















//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends