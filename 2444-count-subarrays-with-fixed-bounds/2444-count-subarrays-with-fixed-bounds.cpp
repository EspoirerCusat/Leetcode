class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long cnt = 0;
        //sliding window
        int mini,maxi;
        mini = maxi = -1;
        int left = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < minK or nums[i] > maxK){
                mini = maxi = -1;
                left = i+1;
                continue;
            }
            if(nums[i] == minK) mini = i;
            if(nums[i] == maxK) maxi = i;
            if(mini == -1 or maxi == -1) continue;
            cnt += min(mini,maxi) - left + 1;
        }
        return cnt;
    }
};











































