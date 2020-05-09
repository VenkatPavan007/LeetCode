class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        vector<int> global_hash(26,0);
        int k = s1.length();
        
        for(int i=0; i<k; i++)
        {
            ++global_hash[s1[i]-'a'];
        }
        
        int n = s2.length();
        for(int i=0; i<n; i++)
        {
            int j = i+k-1;
            if(j >= n)
                break;
            vector<int> local_hash(26,0);
            for(int k=i; k<=j; k++)
            {
               ++local_hash[s2[k]-'a'];
            }
            if(global_hash == local_hash)
                return true;           
            
        }
        return false;
        
    }
};