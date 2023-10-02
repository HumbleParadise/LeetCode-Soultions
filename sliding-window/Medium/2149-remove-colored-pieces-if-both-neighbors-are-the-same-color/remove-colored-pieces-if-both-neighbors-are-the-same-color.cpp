class Solution {
public:
    bool winnerOfGame(string s) {
        int n = s.length();
        
        if(n < 3) return false;
        int i = 0, j = 1;
        int cntA = 0, cntB = 0;
        
        while(j < n)
        {
            if(s[j] == s[i])
            {
                if(s[j] == 'A')
                {
                    if(j-i+1 < 3) j++;
                    else if(j-i+1 == 3)
                    {
                        cntA++;
                        i++, j++;
                    }
                }
                else if(s[j] == 'B')
                {
                    if(j-i+1 < 3) j++;
                    else if(j-i+1 == 3)
                    {
                        cntB++;
                        i++, j++;
                    }
                    
                }
            }
            else
            {
                i = j;
                j++;   
            }
            
        }
        
        return cntA > cntB ? true : false;
        
    }
};