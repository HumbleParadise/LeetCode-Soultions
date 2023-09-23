class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int i=0,j=0;
        map<int, int> Mp;
        map<int, int> M;
        
        for(int i=0;i<nums.size();i++)
        {
            Mp[nums[i]]++;
        }
        
        int unique = Mp.size();
        int n = nums.size();
        int ans = 0;
        
        while(j < nums.size())
        {
            M[nums[j]]++;
            
            if(M.size() < unique)
            {
                j++;
            }
            else if(M.size() == unique)
            {
                ans += n - j;
                while(M.size() == unique)
                {
                    M[nums[i]]--;
                    if(M[nums[i]] == 0) M.erase(nums[i]);
                    
                    if(M.size() == unique) ans += n-j;
                    i++;
                }
                
                if(M.size() == unique) ans += n-j;
                j++;
            }
        }
        
        return ans;
        
    }
};