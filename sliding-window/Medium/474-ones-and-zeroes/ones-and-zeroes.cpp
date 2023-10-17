class Solution {
    static bool cmp(string &s1, string &s2)
    {
        return s1.length() < s2.length();
    }
    
private:
     int dp[601][101][101];
    
public:
    int dfs(vector<string>&strs, int idx, int cnt_zero, int cnt_one)
    {
        if(idx >= strs.size()) return 0;
        else if(cnt_zero < 0 || cnt_one < 0) return 0;
        
        if(dp[idx][cnt_zero][cnt_one] != -1) return dp[idx][cnt_zero][cnt_one];
        
        string temp = strs[idx];
        int curr_zero = 0, curr_one = 0;
        
        for(int i=0;i<temp.length();i++)
        {
            if(temp[i] == '0') curr_zero++;
            else curr_one++;
        }
        
        int v1 = 0, v2 = 0;
        if(cnt_zero - curr_zero >= 0 && cnt_one - curr_one >= 0) 
        {
            v1 = 1 + dfs(strs, idx+1, cnt_zero - curr_zero, cnt_one - curr_one);
        }
        // else 
        {
            v2 = dfs(strs, idx+1, cnt_zero, cnt_one);
        }
        
        return dp[idx][cnt_zero][cnt_one] = max(v1, v2);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        int ans = INT_MIN;
        memset(dp, -1, sizeof(dp));
        
        // sort(strs.begin(), strs.end(), cmp);
        
        return dfs(strs, 0, m, n);
        
        
    }
};