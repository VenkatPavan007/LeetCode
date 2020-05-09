class Solution {
public:
    int findBestValue(vector<int>& arr, int target) 
    {
        int max_ele = -1;
        int n = arr.size();
        for(int i=0; i<n; i++)
            if(arr[i] > max_ele)
                max_ele = arr[i];
        int low = 0, high = max_ele+1;
        int diff = INT_MAX;
        int sum = 0, ans;
        while(low <= high)
        {
            sum = 0;
            int mid = low + (high - low)/2;
            for(int i=0; i<n; i++)
                sum+= (arr[i]<=mid) ? arr[i] : mid;
            
            if(sum == target)
                return mid;
            
            // first update diff
            if(abs(sum - target) < diff)
            {
                diff = abs(sum - target);
                ans = mid;
            }
            
            if(sum > target)
                high = mid - 1;
            else
                low = mid +1;
        }
        return ans;
    }
    
};