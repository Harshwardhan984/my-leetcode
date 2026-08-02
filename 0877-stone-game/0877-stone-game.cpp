class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        // dp[l][r] = maximum score difference the current player
        // can achieve over the opponent from piles[l...r]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: only one pile remains
        for (int i = 0; i < n; i++)
            dp[i][i] = piles[i];

        // Fill by increasing interval length
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                dp[l][r] = max(
                    piles[l] - dp[l + 1][r],
                    piles[r] - dp[l][r - 1]
                );
            }
        }

        return dp[0][n - 1] > 0;
    }
};