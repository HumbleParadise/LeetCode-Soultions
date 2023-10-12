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
    int bsL(int start, int end, int target, MountainArray &mountainArr)
    {
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            
            int mid_ele = mountainArr.get(mid);
            
            if(mid_ele == target) return mid;
            else if(mid_ele > target) end = mid - 1;
            else start = mid + 1;
        }
        
        return -1;
    }
    
    int bsR(int start, int end , int target,MountainArray &mountainArr)
    {
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            
            int mid_ele = mountainArr.get(mid);
            
            if(mid_ele == target) return mid;
            else if(mid_ele > target) start = mid + 1;
            else end = mid - 1;
        }
        
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // mountainArr mein BS. thoda se dikat hai mereko
        
//         find the peak ele, then do the bs on 0 to mid, mid+1 to n
        int n = mountainArr.length();
        int idx = -1;
        int start = 0, end = n-1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            int prev = mid - 1;
            int next = mid + 1;
            
            if(prev <= 0) prev = 0;
            if(next >= n) next = n-1;
            
            int mid_ele = mountainArr.get(mid);
            int prev_ele = mountainArr.get(prev);
            
            if(mid_ele > prev_ele &&
               mid_ele > mountainArr.get(next))
            {
                idx = mid;
                break;
            }
            else if(prev_ele > mid_ele) end = mid - 1;
            else  start = mid + 1;
        }
        
        // Now to BS from 0 to idx, and idx+1 to n-1;
        
        int goLeft = bsL(0, idx, target, mountainArr);
        int goRight = bsR(idx+1, n-1, target, mountainArr);
        
        if(goLeft != -1) return goLeft;
        else if(goRight != -1) return goRight;
        
        return -1;
        
        
    }
};