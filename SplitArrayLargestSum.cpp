class Solution {
public:
    
    bool isSatisfiable(vector<int>&arr, int cuts, int k )
    {
        long sum = 0, n = arr.size();
        for(int i = 0; i<n ; i++)
        {            
            if(sum + arr[i] <= k)
                sum += arr[i];
            
            else if(arr[i] > k)
                return false;
            
            else
            {
                sum = arr[i];
                --cuts;
            }
        }
        if(cuts >= 0)
            return true;
        return false;
    }
    
    int BS(long low, long high, vector<int>& arr, int cuts)
    {
        int ans;
        long start = low;
        long end = high;
        while(start <= end)
        {
            long mid = start + (end - start)/2;            
            if(isSatisfiable(arr, cuts, mid))
            {                
                ans = mid;
                end = mid - 1;                
            }
            else
                start = mid + 1;
        }
        return ans;
    }
    
    int splitArray(vector<int>& arr, int m) 
    {
        int n = arr.size();
        long max_ele = INT_MIN;
        long sum = 0;
        for(int i=0; i<n; i++)
        {
            if(arr[i] > max_ele)
                max_ele = arr[i];
            sum += arr[i];
        }
        --m;
        return BS(max_ele, sum, arr, m);
        
    }
};