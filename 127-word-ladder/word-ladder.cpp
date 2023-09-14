class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        set<string> s;
        
        for(string ite: wordList) 
            s.insert(ite);
        
        q.push({beginWord, 1});
        
        while(q.size() != 0)
        {
            string cmp = q.front().first;
            int len = q.front().second;
            q.pop();
            
            if(cmp == endWord) return len;
            
            // change every char of hit from 1 to 26 char
            for(int i=0;i<cmp.length();i++)
            {
                char ori = cmp[i];
                for(char ch = 'a'; ch <= 'z' ; ch++)
                {
                    cmp[i] = ch;
                    
                    if(s.count(cmp) > 0)
                    {
                        q.push({cmp, len+1});
                        s.erase(cmp);
                    }
                    
                }
                
                cmp[i] = ori;

            }
        }
        
        return 0;
        
    }
};