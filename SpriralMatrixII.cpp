class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> arr;
        arr.assign(n, vector<int>(n, 0));
        int t = 0 ,l = 0,r = n-1,b = n-1;
        int dir = 0;
        int value = 1;
        while(t<=b && l<=r)
        {
            if(dir == 0)
            {
                for(int i = l; i<=r; i++)
                {
                    arr[t][i] = value;
                    ++value;
                }
                ++t;                
            }
            
            else if(dir == 1)
            {
                for(int i=t; i<=b; i++)
                {
                    arr[i][r] = value;
                    ++value;
                }
                --r;
            }
            
            else if(dir == 2)
            {
                for(int i = r; i>=l; i--)
                {
                    arr[b][i] = value;
                    ++value;
                }
                --b;
            }
            else if(dir == 3)
            {
                for(int i = b; i>=t; i--)
                {
                    arr[i][l] = value;
                    ++value;
                }
                ++l;
            }
            dir = (dir+1)%4;
        }
        return arr;
    }
};