class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int sum=0;
        int i=0,j=0;
        while(i<nums.size() && j<nums.size()){
            sum = sum + nums[j];

            if(sum ==k){
                count++;
                j++;
            }else if(sum <k){
                j++;
            }else if(sum >k){
                while(sum>k and i<=j){
                    sum = sum - nums[i];
                    i++;
                }
                sum = sum-nums[j];
            }
        }
        return count;
    }
};
