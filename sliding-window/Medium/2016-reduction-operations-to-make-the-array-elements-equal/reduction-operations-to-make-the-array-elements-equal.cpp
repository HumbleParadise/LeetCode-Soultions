class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int, int> Mp;
        
        for(int i=0;i<nums.size();i++)
        {
            Mp[nums[i]]++;
        }
        
        int ans = 0;
        int min_ele = INT_MAX;
        int sz = 0;
        
        for(auto ite: Mp)
        {
            min_ele = min(min_ele, ite.first);
            int cnt = ite.second;
            
            ans += cnt * sz;
            sz++;
            
        }
        
        return ans;
        
    }
};