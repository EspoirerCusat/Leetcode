class Solution {
public:
    
    int dfs(vector<int> adj[], int src, int par, int req,vector<int>& nums){
        int sum = 0;
        for(int x : adj[src]){
            if(x != par){
                sum += dfs(adj,x,src,req,nums);
            }
        }
        sum += nums[src];
        if(sum == req) return 0;
        return sum;
    }
    
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        
        vector<int> fact;
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        for(int i=1; i*i<=sum; i++){
            if(sum%i == 0){
                fact.push_back(i);
                if(sum/i != i){
                    fact.push_back(sum/i);
                }
            }
        }
        
        int n = nums.size();
        vector<int> adj[n];
        for(auto& itr : edges){
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        int ans = 0;
        for(int x : fact){
            int isPossible = dfs(adj,0,-1,x,nums);
            if(isPossible == 0){
                //cout<<x<<" ";
                ans = max(ans,(sum/x) - 1);
            }
        }
        return ans;
    }
};
















