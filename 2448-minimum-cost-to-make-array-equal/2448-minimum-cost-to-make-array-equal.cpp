class Solution {
public:
    long long f(vector<int>& nums, vector<int>& cost, int x){
        long long ans = 0L;
        for(int i=0; i<nums.size(); i++){
            ans += (long long)abs(nums[i]-x)*cost[i];
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int l = *min_element(nums.begin(),nums.end());
        int r = *max_element(nums.begin(), nums.end());
        long long ans = LLONG_MAX;
        while(l <= r){
            int m1 = l + (r-l)/3;
            int m2 = r - (r-l)/3;
            long long f1 = f(nums,cost,m1);
            long long f2 = f(nums,cost,m2);
            if(f1 > f2){
                l = m1+1;
            }else if(f2 > f1){
                r = m2-1;
            }else{
                l = m1+1; r = m2-1;
            }
            ans = min({ans,f1,f2});
        }
        return ans;   
    }
};