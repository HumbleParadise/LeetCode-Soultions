class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        set<int> s;
        int n = arr.size();
        unordered_map<int, long long> Mp;
        sort(arr.begin(), arr.end());
        int ans = 0;
        
        int mod = 1e9 + 7;
        
        for(int i=0;i<n;i++)
        {
            s.insert(arr[i]);
            Mp[arr[i]]++;
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int root = arr[i];
                int left = arr[j];
               if(root%arr[j] == 0 && arr[j] < root)
               {
                   int right = root/left;
                   if(s.count(right) > 0)
                   {
                       
                       // int left = arr[j];
                       // int right = ele;
                       
                       Mp[root] += (Mp[left] * Mp[right]);
                   }
               }
                  
            }
        }
        
        for(auto ite: Mp) ans = (ans + ite.second)%mod;
        
        return ans;
        
    }
};