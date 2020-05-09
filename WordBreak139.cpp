class Solution {
public:    
    // recursive soln giving TLE
    bool checkWordBreak(string s, int startidx, int n, unordered_set<string>& hash)
    {
        
        if(startidx == n)
            return true;
        string temp = "";
        for(int i=startidx; i<n; i++)
        {
            temp += s[i];
            if(hash.find(temp)!= hash.end())
            {
                int x = startidx + temp.length();
                if(checkWordBreak(s, x, n, hash))
                    return true;                
            }
        }
        return false;
        
    }
    
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int m = wordDict.size();
        unordered_set<string> hash;
        for(int i=0; i<m; i++)
            hash.insert(wordDict[i]);
        
        string temp = "";
        int n = s.length();
        vector<bool> dp(n, 0);
        for(int i=0; i<n; i++)
        {
            temp+=s[i];
            if(hash.find(temp) != hash.end())
            {
                dp[i] = true;  
                continue;
            }
            
            for(int j=0; j<i; j++)
            {                
                if(dp[j] == 1 && hash.find(temp.substr(j+1))!= hash.end())
                {                    
                    dp[i] = true;
                    break;
                }
            }                    
        } 
        
        return dp[n-1]; 
            
       
    }
};