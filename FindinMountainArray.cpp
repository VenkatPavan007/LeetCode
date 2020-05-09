/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    
    int findMountainElement(MountainArray &arr)
    {
        int n = arr.length();
        int low = 0;
        int high = n-1;
        int mid;
        while(low<=high)
        {
            mid = low + (high - low)/2;
            int mid_ele = arr.get(mid);
            int mid_left, mid_right;
            
            
            if(mid - 1 >= 0)
                mid_left = arr.get(mid-1);
            else
                low = mid+1;
            
            if(mid + 1 < n)
                mid_right = arr.get(mid+1);
            else
                high = mid -1;
            
                      
            if(mid_ele > mid_left && mid_ele > mid_right)
                return mid;
            else if(mid_left < mid_ele && mid_ele < mid_right)  // left 
                low = mid+1;
            else
                high = mid -1;
        }
        return mid;
    }
    
    int findTarget1(int low, int high, int target, MountainArray &arr)
    {
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            int mid_ele = arr.get(mid);
            if(mid_ele == target)
                return mid;
            
            else if(mid_ele < target)
                low = mid + 1;
            else
                high = mid - 1;                
                
        }
        return -1;
    }
    
    int findTarget2(int low, int high, int target, MountainArray &arr)
    {
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            int mid_ele = arr.get(mid);
            
            if(mid_ele == target)
                return mid;
            
            else if(mid_ele < target)
                high = mid -1;
            else
                low = mid + 1;      
                
        }
        return -1;
    }
    
    
    
    int findInMountainArray(int target, MountainArray &arr) 
    {
        int n = arr.length();
        int mountainIndex = findMountainElement(arr);
        int ans = findTarget1(0, mountainIndex, target, arr);
        if(ans == -1)
        {
            if(mountainIndex == n)
                return -1;
            else
                ans = findTarget2(mountainIndex+1, n-1, target, arr);
        }
        return ans;
    }
};