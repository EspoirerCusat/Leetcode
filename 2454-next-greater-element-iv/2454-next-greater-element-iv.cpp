class Solution {
public:
    static bool comp(const pair<int,int>& a, const pair<int,int>& b){
        if(a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    }
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> arr;
        for(int i=0; i<n; i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end(),comp);
        set<int> s;
        //Largest -> smallest
        vector<int> ans(n,-1);
        for(int i=0; i<n; i++){
            int x = arr[i].first;
            int idx = arr[i].second;
            auto itr = s.upper_bound(idx); 
            if(itr != s.end()){
                itr++;
                if(itr != s.end()){
                    ans[idx] = nums[*itr];
                }
            }
            s.insert(idx);
        }
        return ans;
    }
};


























