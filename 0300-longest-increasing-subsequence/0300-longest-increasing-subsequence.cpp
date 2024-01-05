class Solution {
public:
int f(int ind,int prev_ind,vector<int> &nums,vector<vector<int>> &dp){

    if(ind>=nums.size()) return 0;

    if(dp[prev_ind+1][ind] != -1) return dp[prev_ind+1][ind];

    int nonpick = f(ind+1,prev_ind,nums,dp);

    int pick = 0;

    if(prev_ind == -1 || nums[ind]>nums[prev_ind]){
        pick = 1 + f(ind+1,ind,nums,dp);
    }

    return dp[prev_ind+1][ind] =  max(pick,nonpick);
}
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return f(0,-1,nums,dp);
    }
};