class Solution {
public:
    bool lemonadeChange(vector<int>& bills)
    {
        int n = bills.size();        
        int fives = 0, tens = 0;
        for(int i=0; i<n; i++)
        {
            if(bills[i] == 5)
                ++fives;
            else if(bills[i] == 10)
            {
                ++tens;
                if(fives > 0)
                    --fives;
                else
                    return false;
            }
            else
            {
                if(tens > 0)
                {
                    if(fives > 0)
                    {
                        --tens;
                        --fives;
                    }
                    else
                        return false;
                }
                else if(fives >=3)
                    fives -= 3;
                else
                    return false;
                
            }
        }
        return true;
    }
};