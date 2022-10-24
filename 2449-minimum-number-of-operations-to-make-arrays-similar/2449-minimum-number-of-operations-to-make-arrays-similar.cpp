class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<long long> odd1,even1;
        vector<long long> odd2,even2;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]&1) odd1.push_back(nums[i]);
            else even1.push_back(nums[i]);
        }
        for(int i=0; i<target.size(); i++){
            if(target[i]&1) odd2.push_back(target[i]);
            else even2.push_back(target[i]);
        }
        sort(odd1.begin(),odd1.end());
        sort(even1.begin(),even1.end());
        sort(odd2.begin(),odd2.end());
        sort(even2.begin(),even2.end());
        long long ans = 0LL;
        for(int i=0; i<odd1.size(); i++){
            ans += abs(odd1[i]-odd2[i]);
        }
        for(int i=0; i<even1.size(); i++){
            ans += abs(even1[i]-even2[i]);
        }
        ans /= 4;
        return ans;
    }
};