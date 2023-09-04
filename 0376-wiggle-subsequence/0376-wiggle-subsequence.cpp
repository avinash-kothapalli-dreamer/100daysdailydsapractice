class Solution {
public:
   int DP(int ind, int prev, int pos, vector<int> &nums, int n, vector<vector<vector<int>>> &dp)
{
    if (ind >= n)
    {
        return 0;
    }

    if (dp[ind][prev + 1][pos] != -1)
    {
        return dp[ind][prev + 1][pos];
    }

    if (pos)
    {
        int pick = 0;
        int nonpick = 0;
        if (prev == -1 or nums[ind] - nums[prev] < 0)
        {
            pick = 1 + DP(ind + 1, ind, 0, nums, n, dp);
        }
        nonpick = 0 + DP(ind + 1, prev, 1, nums, n, dp);
        return dp[ind][prev + 1][pos] = max(pick, nonpick);
    }
    else
    {
        int pick = 0;
        int nonpick = 0;

        if (prev == -1 or nums[ind] - nums[prev] > 0)
        {
            pick = 1 + DP(ind + 1, ind, 1, nums, n, dp);
        }
        nonpick = 0 + DP(ind + 1, prev, 0, nums, n, dp);
        return dp[ind][prev + 1][pos] = max(pick, nonpick);
    }
}

int wiggleMaxLength(vector<int> &nums)
{
    int n = nums.size();
    // return max(solve(0, -1, 0, nums, n), solve(0, -1, 1, nums, n));

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1, vector<int>(2, -1)));
    return max(DP(0, -1, 0, nums, n, dp), DP(0, -1, 1, nums, n, dp));
}
};