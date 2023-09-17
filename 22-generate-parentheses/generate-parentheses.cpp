class Solution {
public:
    
   void solve(int o,int c,string op, vector<string> &v)
    {
        if(o == 0 && c == 0)
        {
            v.push_back(op);
            return;
        }
        
        if(o != 0)
        {
            string op1 = op;
            
            op1.push_back('(');
            // ip.erase(ip.begin()+0);
            
            solve(o-1,c,op1,v);
        }
        
        if(c > o)
        {
            string op2 = op;
            op2.push_back(')');
            // ip.erase(ip.begin()+0);
            
            solve(o,c-1,op2,v);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        int o = n;
        int c = n;
        
        string op = "";
        vector<string> v;
        solve(o,c,op,v);
        
        return v;
        
    }
};