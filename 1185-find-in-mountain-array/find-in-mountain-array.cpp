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
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int start = 0;
        int end = mountainArr.length()-1;
         while(start < end){
            int mid = (start + end)/2;
            if(mountainArr.get(mid)>mountainArr.get(mid+1)){
                end = mid;
            }else{
                start = mid+1;

            }

            
            
        }
        int peak = start;
            int res = search(mountainArr,target,0,peak);
            if(res == -1){
                return search(mountainArr,target,peak+1,mountainArr.length()-1);
            }
            return res;
            
    }

    int search(MountainArray &mountainArr,int target,int start, int end){
        bool asc = mountainArr.get(start) < mountainArr.get(end)?true:false;

        while(start <= end){
            int mid = (start + end)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }else if(mountainArr.get(mid) > target){
                if(asc){
                    end = mid-1;
                }else{
                    start = mid +1;
                }
            }else{
                 if(asc){
                    start = mid +1;
                    
                }else{
                   end = mid-1; 
                }

            }
            
        }
        return -1;
    }
};