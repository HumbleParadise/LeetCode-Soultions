class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // how to get susbequence without generating all possible combinations
        // start and end and just check the ele between them    
        
        map<char, int> Mp;
        int cnt = 0;
        
        for(int i=0;i<s.length();i++)
        {
            int start = i,  end = -1;
            
            if(Mp[s[i]] == 0)
            {
                Mp[s[i]] = 1;
                size_t lastPos = s.rfind(s[i]);
                if(lastPos != string::npos)
                {
                    end = lastPos; 
                }
                
                // check the dist between firstpos and lastpos
                if(end != -1 && (end - start + 1) >= 3)
                {
                    set<char> mid;
                    int pos = start + 1;
                    while(pos < end)
                    {
                        if(mid.count(s[pos]) == 0) 
                        {
                            cnt++;
                            mid.insert(s[pos]);
                        }
                        pos++;
                    }
                    
                }
            }
        }
        
        // for(auto ite: Mp) cout << ite.first << " " << ite.second << endl;
        return cnt;
        
    }
};