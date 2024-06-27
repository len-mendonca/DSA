class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int> exMap;
       for(int i=0;i<nums.size();i++){
        int rem = target - nums[i];
        if(exMap.count(rem)){
            return {exMap[rem],i};
        }
        exMap[nums[i]]=i;
       }
       return {};
};
};