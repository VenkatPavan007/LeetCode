class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank)
    {       
              
        int n = bank.size();
        vector<bool> visited(n, false);
        queue<pair<string, int>> q;  
        q.push({start,0});
        
        
        while(!q.empty())
        {
            string s = q.front().first;
            int level = q.front().second;
            if(s == end)
                return level;
            q.pop();
            for(int i=0; i<n; i++)
            {
                int r = s.length();
                int t = bank[i].length();
                int change = 0;
                if(r == t && visited[i] == false)
                {                    
                    for(int j=0; j<r; j++)
                    {
                        if(s[j] != bank[i][j])
                            ++change;
                    }
                    if(change == 1)
                    {
                        q.push({bank[i], level+1});
                        visited[i] = true;
                    }
                        
                }
            }
        }
        return -1;
    }
};