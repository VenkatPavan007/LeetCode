class Solution {
public:
    int countBinarySubstrings(string s) 
    {
        int n = s.length();
        vector<int> groups;
        for(int i=0; i<n; i++)
        {
            int size = 1;            
            int j = i+1;
            while(j<n && s[j] == s[i])
            {
                ++j;
                ++size;
            }
            i = j-1;
            groups.push_back(size);
        }
        int ans = 0;
        for(int i = 0; i<(groups.size()-1); i++)
        {
            ans += min(groups[i], groups[i+1]);
        }
        return ans;
    }
};