class Solution {
    private:
        int dp[1001][1001];
    
public:
    int dfs(int i, int j, string &a, string &b)
    {
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(a[i] == b[j]) return dp[i][j] = 1 + dfs(i-1, j-1, a, b);
        else return dp[i][j] = max({dfs(i-1, j, a, b), dfs(i, j-1, a, b)});
    }
    
    int longestPalindromeSubseq(string s) {
        string a = s;
        string b;
        reverse(s.begin(), s.end());
        b = s;
        
        cout << a << endl << b;
        
        memset(dp, -1, sizeof(dp));
        return dfs(a.length()-1, b.length()-1, a, b);
        
    }
};