class Solution {
public:
    bool carPooling(vector<vector<int>>& arr, int total)
    {
        int n = arr.size();
        vector<int> prefix(1001,0);
        for(int i=0; i<n; i++)
        {
            int start = arr[i][1], end = arr[i][2], capacity = arr[i][0];
            
            prefix[start] += capacity;
            prefix[end] += -1*capacity;           
           
        }
        for(int i = 1; i<=1000; i++)
        {
            prefix[i] += prefix[i-1];
            if(prefix[i]> total)
                return false;
        }
        return true;
    }
};