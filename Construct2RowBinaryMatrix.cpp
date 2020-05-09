class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum)
    {
        int n = colsum.size();
        
        vector<vector<int>>res(2, vector<int>(n,0));        
        for(int i=0; i<n; i++)
        {
            
            if(colsum[i] == 2)
            {   
                if(upper == 0 || lower == 0)
                     return vector<vector<int>>();
                res[0][i] = 1;
                res[1][i] = 1;
                --upper;
                --lower;
            }
            
            else if(colsum[i] == 1)
            {   
                if(upper == 0 && lower == 0)
                     return vector<vector<int>>();
                if(upper >= lower)
                {
                    res[0][i] = 1;
                    --upper;
                }                
                else 
                {
                    res[1][i] = 1;
                    --lower;
                }                 
            }
            
        }
        if(upper > 0 || lower > 0)
           return vector<vector<int>>();
        
           
        return res;
        
    }
};