class Solution {
    private: 
        // int dp[1001][1001];

public:
    int dfs(int idx, int prev, vector<pair<int, int>> &v, vector<vector<int>> &dp)
    {
        if(idx >= v.size()) return 0;
        
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
        
        int ope1 = 0, ope2 = 0;
        if(prev == -1 || v[idx].second >= v[prev].second)
        {
            ope1 = v[idx].second + dfs(idx+1, idx, v, dp);
        }
        
        ope2 = dfs(idx+1, prev, v, dp);
        return dp[idx][prev+1] = max(ope1, ope2);
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        // agar sort kara then we get some sure shot 
        
        int n = scores.size();
        vector<pair<int, int>> v; // age and score
        for(int i=0;i<ages.size();i++)
        {
            v.push_back({ages[i], scores[i]});
        }
        
        sort(v.begin(), v.end());
        
        // memset(dp, -1, sizeof(dp));
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return dfs(0, -1, v,dp);
        
    }
};