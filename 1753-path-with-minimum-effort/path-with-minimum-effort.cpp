class Solution {
public:
    bool dfs(int diff, vector<vector<int>>& heights, vector<vector<bool>> &path, int r, int c)
    {
        path[r][c] = true;
        // if(abs(prev - heights[r][c]) > diff) return false; 
        if(r == heights.size()-1 && c == heights[0].size()-1) return true;
        
        
        int vr[] = {-1, 0, +1, 0};
        int vc[] = {0, 1, 0, -1};
        
        // prev = path[r][c]; 
        for(int i=0;i<4;i++)
        {
            int nr = vr[i] + r;
            int nc = vc[i] + c;
            
            if(nr >= 0 && nr < heights.size() && 
               nc >= 0 && nc < heights[0].size() && 
               path[nr][nc] == false)
            {
                
                if(abs(heights[r][c] - heights[nr][nc]) <= diff && dfs(diff, heights, path, nr, nc) == true) return true;
                
            }
        }
        
        return false;
        
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int start = 0, end = 1e6;
        int ans = INT_MAX;
        int n = heights.size(), m = heights[0].size();
        while(start <= end)
        {
            vector<vector<bool>> path(n, vector<bool>(m, false));
            int mid = start + (end - start)/2;
            int r = 0, c = 0;
            if(dfs(mid, heights, path, r, c))
            {
                ans = min(ans, mid);
                end = mid-1;
            }
            else start = mid + 1;
        }
        
        return ans;
    }
};