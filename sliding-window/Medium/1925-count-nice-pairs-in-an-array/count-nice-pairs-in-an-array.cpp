class Solution {
public:
    int MOD = 1e9+7;
    unordered_map<int, long> Map;
    int rev(int ele)
    {
        string temp = "";
        temp = to_string(ele);
        
        string rev = string(temp.rbegin(), temp.rend());
        
        int value = stoi(rev);
        return value;
    }
    
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        long cnt = 0;
        for(int i=0;i<n;i++)
        {
            // if(nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])) cnt = (cnt + 1)%MOD;
            nums[i] = nums[i] - rev(nums[i]);
            Map[nums[i]]++;
            // if(Map.find(nums[i]) != Map.end()) 
            // {
            //     cnt = (cnt + Map[nums[i]])%MOD;
            //     Map[nums[i]]++;
            // }
            // else Map[nums[i]]++;
        }
        
        for(auto ite: Map)
        {
            cnt = (cnt + (ite.second * (ite.second-1))/2)%MOD;
        }
        
        return (int)cnt%MOD;
        
    }
};