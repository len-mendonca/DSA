class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> pos = {-1,-1};
        
        pos[0] = search(nums,0,nums.size()-1,true,target);
        pos[1] = search(nums,0, nums.size()-1,false,target);

        return pos;
        
    }
     int search(vector<int> num,int start, int end,bool findFirst,int target){
            int l =start;
            int r = end;
            int present =-1;
            while(l<=r){
                int mid = (l+r)/2;
                if(target < num[mid]){
                    r = mid-1;
                }else if(target > num[mid]){
                    l = mid+1;
                }else{
                    present = mid;
                    if(findFirst){
                        r = mid-1;
                    }else{
                        l = mid+1;
                    }

                }
            }
            return present;

        }
};