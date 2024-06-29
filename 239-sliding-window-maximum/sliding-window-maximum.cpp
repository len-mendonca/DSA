class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> list;
        vector<int> ans;
        int i=0,j=0;
        while(j<nums.size()){
           

            while(!list.empty() && (list.back() < nums[j])){
                list.pop_back();
            }
            list.push_back(nums[j]);

            if(j-i+1 <k){
                j++;
            }else if(j-i+1 == k){
                ans.push_back(list.front());

                if(nums[i]==list.front()){
                    list.pop_front();
                }
                i++;
                j++;
            }
           
        }
        return ans;
    }
};