class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p1 = 0;
        int p2 = numbers.size() -1;
        int sum;

        while(p1<p2){
            sum = numbers[p1]+ numbers[p2];

            if(sum == target){
                return {p1+1,p2+1};
            }else if(sum>target){
                p2--;
            }else{
                p1++;
            }

        }
        return {};
    }
};