class Solution {
public:
    vector<string> ans;
    unordered_set<string> st;
    
    void solve(string ip, string op)
    {
        if(ip.size() == 0)
        {
            if(st.count(op) == 0) ans.push_back(op);
            
            return;
        }
        
        string op1 = op;
        string op2 = op;
        
        op1 += ip[0];
        op2 += '1';
        
        ip.erase(ip.begin() + 0);
        
        solve(ip, op1);
        if(ans.size() != 0) return;
        
        solve(ip, op2);
        if(ans.size() != 0) return;
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ip(n, '0');
        string op = "";
        
        for(string ite: nums) st.insert(ite);
        
        solve(ip, op);
        
        return ans[0];
    }
};