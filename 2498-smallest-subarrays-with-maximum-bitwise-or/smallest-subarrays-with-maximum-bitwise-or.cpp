class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos(30);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--)
        {
            int ele = nums[i];
            for(int j=0;j<31;j++)
            {
                if(ele & (1 << j))
                {
                    pos[j] = i;
                }
            }
            
            int end = *max_element(pos.begin(), pos.end());
            int sz = max(end, i) - i + 1;
            ans[i] = sz;

        }
        
        return ans;
    }
};