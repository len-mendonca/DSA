class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        int maxSum=0;
        int rIndex = cardPoints.size() -1; 
        for(int lIndex=0;lIndex<k;lIndex++){
            sum+=cardPoints[lIndex];
        }
        maxSum = sum;
        
        for(int lIndex=k-1;lIndex>=0;lIndex--){
            sum = sum - cardPoints[lIndex];
            sum = sum+ cardPoints[rIndex];
            maxSum = max(maxSum,sum);
            rIndex--;
        }

        return maxSum;

    }
};