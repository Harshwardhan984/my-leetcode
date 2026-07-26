class Solution {
public:
    bool solve(vector<int>& nums, int i, vector<int>& dp) {
        if(i >= nums.size()-1) return true;
        if(dp[i] != -1) return dp[i];
        
        for(int jump = 1; jump <= nums[i]; jump++) {
            if(solve(nums, i+jump, dp)) return dp[i] = true;
        }
        return dp[i] = false;
    }
    
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};
