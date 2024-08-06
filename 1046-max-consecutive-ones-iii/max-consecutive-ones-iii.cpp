class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,zeroCount=0,maxLen=0;
        deque<int> zeroPositions;

        while(r<nums.size()){
            if(nums[r] ==0 ){
                zeroCount++;
                zeroPositions.push_front(r);
            }
            if(zeroCount>k){
                l = zeroPositions.back() + 1; 
                zeroPositions.pop_back();
                zeroCount--;
            }
            maxLen = max(maxLen,r-l+1);
            r++;

        }
        return maxLen;
    }
};